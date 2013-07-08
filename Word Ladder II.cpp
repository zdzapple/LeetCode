class Solution 
{
public:
	void buildPath(map<string, vector<string> > &traces, vector<string> &path, string &word, vector<vector<string> >& result)
	{
		if (traces[word].size() == 0) {
			path.push_back(word);
			vector<string> curPath = path;
			reverse(curPath.begin(), curPath.end());
			result.push_back(curPath);
			path.pop_back();
			return;
		}

		const vector<string> &prevs = traces[word];
		path.push_back(word);
		for (vector<string>::const_iterator citr = prevs.begin();
			citr != prevs.end(); citr ++) {
				string str = *citr;
				buildPath(traces, path, str, result);
		}
		path.pop_back();
	}

	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) 
	{
		vector<vector<string>> result;
		if (start.empty() || end.empty() || dict.empty())  
			return result;  
		if (start == end)
			return result;

		vector<string> path;
		queue<string> q;
		map<string, vector<string> > traces;  
		dict.insert(end);
		dict.erase(start); // important! 否则会出现map中循环引用的情况
		vector<string> s;
		for (unordered_set<string>::const_iterator citr = dict.begin();   
			citr != dict.end(); citr ++) {  
				traces[*citr] = s;  
		} 
		int preLevelNum = 1;
		int levelNum = 0;
		q.push(start);
		vector<string> visited;
		set<string> queueSet; // 将queue中的元素去重。如果在traces中使用set也是可以的，但在跑large的时候会超时。所以要先去重
		while (true)
		{
			levelNum = 0;
			bool isOver = false;			
			for (int i = 0; i < visited.size(); ++ i)
				dict.erase(visited[i]);
			visited.clear();
			queueSet.clear();
			while (preLevelNum > 0)
			{
				preLevelNum --;
				string current = q.front();
				q.pop();
				if (queueSet.count(current) > 0)
					continue;
				queueSet.insert(current);
				for (int i = 0; i < current.size(); ++ i)
				{
					char temp = current[i];
					for (char ch = 'a'; ch <= 'z'; ++ ch)
					{
						if (ch != temp) {
							string newStr(current);
							newStr[i] = ch;
							if (newStr == end) {
								isOver = true;
							}
							if (dict.find(newStr) != dict.end()) {
								levelNum ++;
								q.push(newStr);
								traces[newStr].push_back(current);
								//dict.erase(newStr); // 可能会erase掉end，而且因为有多个解，所以应该在下次循环的时候erase
								visited.push_back(newStr);
							}
						}
					}
				}
			}
			if (isOver)
				break;
			if (levelNum == 0 || q.empty())
				return result;
			preLevelNum = levelNum;

		}
		buildPath(traces, path, end, result);  
		return result;
	}
};