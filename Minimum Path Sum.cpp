class Solution 
{
public:
    int minPathSum(vector<vector<int> > &grid) 
	{
        int result = 0;
		if (grid.empty())
			return result;
		int m = grid.size();
		int n = grid[0].size();
		// dp[i, j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
		vector<vector<int> > dp(m, vector<int>(n, 0));
		dp[0][0] = grid[0][0];
		for (int i = 1; i < m; ++ i)
			dp[i][0] = dp[i-1][0] + grid[i][0];
		for (int i = 1; i < n; ++ i)
			dp[0][i] = dp[0][i-1] + grid[0][i];
		for (int i = 1; i < m; ++ i)
		{
			for (int j = 1; j < n; ++ j)
			{
				dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
			}
		}
		return dp[m-1][n-1];
		
        
    }
};
/*
提交了好多次才accepted..
1. 刚开始dp的下标从1开始，所以想着没有初始化14~17行
2. 改成从0开始，初始化了14~17行，但吧dp[0][i] = dp[0][i-1] + grid[0][i];写成了dp[0][i] = grid[0][i-1] + grid[0][i];

*/