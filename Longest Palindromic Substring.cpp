class Solution 
{
public:
	// dp version
	// p[i][j] = true if s[i..j] is palindrome
	// p[i-1][j+1] = true if p[i][j] = true && s[i-1]==s[j+1]
	// O(n2)
    string longestPalindromeDP(string s) 
	{
        int n = s.size();
		string result;
		if (s.empty())
			return "";
		vector<vector<bool> > dp(n, vector<bool>(n, false));
		int longestBegin = 0;
		int maxLen = 1;
		for (int i = 0; i < n; ++ i)
			dp[i][i] = true;
		for (int i = 0; i < n - 1; ++ i)
			if (s[i] == s[i+1])	{
				dp[i][i+1] = true;
				maxLen = 2;
				longestBegin = i;
			}
        for (int len = 3; len <= n; ++ len)
		{
			for (int i = 0; i <= n - len; ++ i)
			{
				int j = i + len - 1;
				if (s[i] == s[j] && dp[i+1][j-1]) {
					dp[i][j] = true;
					longestBegin = i;
					maxLen = len;
				}
			}
		}
		return s.substr(longestBegin, maxLen);
    }
	
	string expandAroundCenter(string s, int l, int r) 
	{
		while (l >= 0 && r <= s.size() - 1 && s[l] == s[r])
		{
			l --;
			r ++;
		}
		return s.substr(l+1, r-l-1);
	}
	
	string longestPalindrome2(string s) 
	{
        int n = s.size();
		string result;
		if (s.empty())
			return "";
		string longest = s.substr(0, 1);
		for (int i = 0; i < n - 1; ++ i)
		{
			string s1 = expandAroundCenter(s, i, i);
			if (s1.size() > longest.size())
				longest = s1;
			string s2 = expandAroundCenter(s, i, i + 1);
			if (s2.size() > longest.size())
				longest = s2;
		}
		return longest;
	}
	
	// http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
	// Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each end to avoid bounds checking
	string preProcess(string s) 
	{
		int n = s.length();
		if (n == 0) return "^$";
		string ret = "^";
		for (int i = 0; i < n; i++)
			ret += "#" + s.substr(i, 1);
	 
		ret += "#$";
		return ret;
	}
	 
	string longestPalindrome(string s) 
	{
		string T = preProcess(s);
		int n = T.length();
		int *P = new int[n];
		int C = 0, R = 0;
		for (int i = 1; i < n-1; i++) 
		{
			int i_mirror = 2*C-i; // equals to i' = C - (i-C)
		
			P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
		
			// Attempt to expand palindrome centered at i
			while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
				P[i]++;
	 
			// If palindrome centered at i expand past R,
			// adjust center based on expanded palindrome.
			if (i + P[i] > R) {
				C = i;
				R = i + P[i];
			}
		}
	 
		// Find the maximum element in P.
		int maxLen = 0;
		int centerIndex = 0;
		for (int i = 1; i < n-1; i++) {
			if (P[i] > maxLen) {
				maxLen = P[i];
				centerIndex = i;
			}
		}
		delete[] P;
	  
		return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
	}
};