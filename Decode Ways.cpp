class Solution 
{
public:
	// special case: 0/ 003/ 300 / 10 /101 / 24726
    int numDecodings(string s) 
	{
		if (s.empty())
			return 0;
		int n = s.size();
		vector<int> result(n, 0);
		if (s[0] >= '1')
			result[0] = 1;
		else 
			return 0;
		for (int i = 1; i < n; ++ i)
		{
			int num = atoi(s.substr(i-1, 2).c_str());
			if (s[i] == '0' && (num > 26 || num == 0))
				return 0;
			
			if (num <= 26 && num >= 1 && s[i] != '0' && s[i-1] != '0')
				result[i] = (i >= 2 ? result[i-2] + result[i-1] : 2);
			else if (s[i] == '0') 
				result[i] = (i >= 2 ? result[i-2] : 1);
			else  // 101
				result[i] = result[i-1];
				
			
		}
		return result[n-1];
        
    }
};