class Solution 
{
public:
 // 248ms
    vector<string> anagrams1(vector<string> &strs) 
	{
		vector<string> result;
		map<string, vector<string> > dict;
		if (strs.empty())
			return result;
		for (int i = 0; i < strs.size(); ++ i)
		{
			string s(strs[i]);
			sort(s.begin(), s.end());
			dict[s].push_back(strs[i]);
		}
		vector<string>::iterator st = strs.begin();
		map<string, vector<string> >::iterator it = dict.begin();
		for (; it != dict.end(); ++ it)
		{
			if (it->second.size() > 1) {
				for(st = it->second.begin(); st != it->second.end(); st ++)
					result.push_back(*st);
			}
		}
		return result;
    }
	
	vector<int> fingerPrint(string str)
	{
		vector<int> key(26, 0);
		for (int i = 0; i < str.size(); ++ i)
		{
			key[str[i] - 'a'] ++;
		}
		return key;
	}
	// using a int vector[26] to caculate the fingerPrint of the str
	// 304ms
	vector<string> anagrams(vector<string> &strs) 
	{
		vector<string> result;		
		if (strs.empty())
			return result;
		map<vector<int>, vector<string> > dict;	
		vector<string>::iterator st = strs.begin();
		for (; st != strs.end(); ++ st)
		{
			dict[fingerPrint(*st)].push_back(*st);
		}
		map<vector<int>, vector<string> >::iterator it = dict.begin();
		for (; it != dict.end(); ++ it)
		{
			if (it->second.size() > 1) {
				for(st = it->second.begin(); st != it->second.end(); st ++)
					result.push_back(*st);
			}
		}
		return result;
	}
};