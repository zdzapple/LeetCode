class Solution 
{
public:
    string longestCommonPrefix(vector<string> &strs) 
	{
		if (strs.empty())
			return "";
		if (strs.size() == 1)
			return strs[0];
		string result = "";
		int n = 0;
		char ch;
		while (true)
		{
			if (n < strs[0].size()) {
				ch = strs[0][n];
			} else
				break;
			for (int i = 1; i < strs.size(); ++ i)
			{
				if (n < strs[i].size()) {
					if (ch != strs[i][n])
						return result;
				} else {
					return result;
				}
			}
			result += ch;
			n ++;
		}
		return result;
        
        
    }
};