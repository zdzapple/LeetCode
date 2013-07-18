class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) 
	{
        int len1 = s1.size();
		int len2 = s2.size();
		int len3 = s3.size();
		if (len1 + len2 != len3)
			return false;
		// match[i][j] == ture if s3 is formed by the interleaving of s1[1:i] and s2[1:j]
		vector<vector<bool> > match(len1 + 1, vector<bool>(len2 + 1, false));
		match[0][0] = true;
		for (int i = 1; i <= len1; ++ i)
		{
			if (s1[i-1] == s3[i-1])
				match[i][0] = true;
			else 
				break;
		}
		for (int i = 1; i <= len2; ++ i)
		{
			if (s2[i-1] == s3[i-1])
				match[0][i] = true;
			else 
				break;
		}
		for (int i = 1; i<= len1; ++ i)
		{
			char c1 = s1[i-1];
			for (int j = 1; j <= len2; ++ j)
			{
				char c2 = s2[j-1];
				char c3 = s3[i+j-1];
				if (c1 == c3)
					match[i][j] = match[i][j] || match[i-1][j];
				if (c2 == c3)
					match[i][j] = match[i][j] || match[i][j-1];
			}
		}
		return match[len1][len2];
        
    }
	// 交错，考虑单个字符，而不是一个子串。因为交错的顺序不是固定的
};