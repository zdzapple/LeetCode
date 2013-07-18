class Solution 
{
public:
	// LCS is wrong...
	// case: "ab", "bc"	 1	2	
   //		"sea", "ate" 2  3
	int LCS(string word1, int m, string word2, int n)
	{
		// the longest common sequence
		// dp[i][j]: the length of common sequence of word1[0..i] and word2[0..j]
		vector<vector<int > > dp(m+1, vector<int>(n+1, 0)); 
		for (int i = 1; i <= m; ++ i) 
		{
			for (int j = 1; j <= n; ++ j)
			{
				if (word1[i-1] == word2[j-1])
					dp[i][j] = dp[i-1][j-1] + 1;
				else  
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
		return dp[m][n];
	}
	
    int minDistance1(string word1, string word2) 
	{
        int m = word1.size();
		int n = word2.size();
		if (word2.empty())
			return m;
		if (word1.empty())
			return n;
		int lcs = LCS(word1, m, word2, n);
		if (m <= n) {
			return n - lcs;
		} else {
			return m - lcs;
		}
    }
	/**
		当我们要计算d(i,j)时，即计算A(i)到B(j)之间的编辑距离，此时，设A(i)形式是somestr1c；B(i)形如somestr2d的话，
        将somestr1变成somestr2的编辑距离已知是d(i-1,j-1)
		将somestr1c变成somestr2的编辑距离已知是d(i,j-1)
		将somestr1变成somestr2d的编辑距离已知是d(i-1,j)
		那么利用这三个变量，就可以递推出d(i,j)了：
		如果c==d，显然编辑距离和d(i-1,j-1)是一样的
		如果c!=d，情况稍微复杂一点，
		如果将c替换成d，编辑距离是somestr1变成somestr2的编辑距离 + 1，也就是d(i-1,j-1) + 1
		如果在c后面添加一个字d，编辑距离就应该是somestr1c变成somestr2的编辑距离 + 1，也就是d(i,j-1) + 1
		如果将c删除了，那就是要将somestr1编辑成somestr2d，距离就是d(i-1,j) + 1
		那最后只需要看着三种谁最小，就采用对应的编辑方案了。
		递推公式：
		dp[i][j] =  dp[i-1][j-1]   if (A[i] == B[j])
           or = min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) +1;
		初始条件： dp[0][j] = j and dp[i][0] = i   
	**/
	int minDistance(string word1, string word2) 
	{
        int m = word1.size();
		int n = word2.size();
		vector<vector<int > > dp(m+1, vector<int>(n+1, 0)); 
		for (int i = 0; i <= n; ++ i)
			dp[0][i] = i;
		for (int i = 0; i <= m; ++ i)
			dp[i][0] = i;
		for (int i = 1; i <= m; ++ i) 
		{
			for (int j = 1; j <= n; ++ j)
			{
				if (word1[i-1] == word2[j-1])
					dp[i][j] = dp[i-1][j-1];
				else  
					dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
			}
		}
		return dp[m][n];
	}
};