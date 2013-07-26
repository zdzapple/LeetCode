class Solution 
{
public:
	// use two map, one notes the occurence of string in L, the other one notes the occurence in the subStr of S. compare the two map to get the result.
    vector<int> findSubstring(string S, vector<string> &L) 
	{
        map<string, int> occurence;
		map<string, int> curStr;
		vector<int> result;
		if (L.empty() || S.empty())
			return result;
		for(int i = 0; i < L.size(); ++ i)
		{	
			if (occurence.count(L[i]) == 0)
				occurence[L[i]] = 1;
			else 
				occurence[L[i]] ++;
		}		 
		int len = L[0].size();
		int N = L.size();
		// S.size() - N * len may overflow, bacause S.size() return site_t(unsigned integral type)
		for (int i = 0; i <= (int) S.size() - N * len; ++ i) 
		{
			curStr.clear();
			int j;
			for (j = 0; j < N; ++ j)
			{
				string str = S.substr(i + j * len, len);
				if (occurence.find(str) == occurence.end())
					break;
				curStr[str] ++;
				if (curStr[str] > occurence[str])
					break;
			}
			if (j == N)
				result.push_back(i);
		}
        return result;
    }
};

// http://discuss.leetcode.com/questions/210/substring-with-concatenation-of-all-words
class Solution2
{
public:
    vector<int> findSubstring(string S, vector<string> &L) 
	{
        int m = S.size(), n = L.size(), len = L[0].size();
        map<string, int> ids;

        vector<int> need(n, 0);
        for (int i = 0; i < n; ++ i) 
		{
            if (!ids.count(L[i])) 
				ids[L[i]] = i;
            need[ids[L[i]]] ++;
        }

        vector<int> s(m, -1);
        for (int i = 0; i < m - len + 1; ++ i)
		{
            string key = S.substr(i, len);
            s[i] = ids.count(key) ? ids[key] : -1;
        }

        vector<int> ret;
        for (int offset = 0; offset < len; ++ offset) 
		{
            vector<int> found(n, 0);
            int count = 0, begin = offset;
            for (int i = offset; i < m - len + 1; i += len) 
			{
                if (s[i] < 0) {
                    // recount
                    begin = i + len;
                    count = 0;
                    found.clear();
                    found.resize(n, 0);
                } else {
                    int id = s[i];
                    found[id] ++;
                    if (need[id] && found[id] <= need[id])
                        count ++;

                    if (count == n)
                        ret.push_back(begin);

                    // move current window
                    if ((i - begin) / len + 1 == n) {
                        id = s[begin];
                        if (need[id] && found[id] == need[id])
                            count--;
                        found[id]--;
                        begin += len;
                    }
                }
            }
        }
        return ret;
    }
};

// Time Limit Exceeded
class Solution1
{
public:
	void swap(vector<string> &L, int i, int j)
	{
		string temp = L[i];
		L[i] = L[j];
		L[j] = temp;
	}
	
	void getAllConcatenation(set<int> &result, vector<string> &L, string S, int s, int e)
	{
		if (s > e) {
			string str;
			for (int i = 0; i <= e; ++ i)
				str += L[i];
			int begin = 0;
			int found;
			while (true)
			{
				if ((found = S.find(str, begin)) != string::npos) {
					result.insert(found);
					begin = found + 1;
				} else 
					break;
			}
			return;
		}
		for (int i = s; i <= e; ++ i)
		{
			swap(L, s, i);
			getAllConcatenation(result, L, S, s + 1, e);
			swap(L, s, i);
		}
	}
	
    vector<int> findSubstring(string S, vector<string> &L) 
	{
		vector<int> result;
        if (L.empty() || S.empty())
			return result;
		set<int> re;
		getAllConcatenation(re, L, S, 0, L.size() - 1);
		if (!re.empty())
		{
			for (set<int>::iterator it = re.begin(); it != re.end(); ++ it)
			{
				result.push_back(*it);
			}
		}
        return result;
    }
};