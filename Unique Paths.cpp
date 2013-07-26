class Solution 
{
public:
	long long factor(int n, int start = 1) 
	{
        long long ret = 1;
        for(int i = start; i <= n; ++ i)
            ret *= i;
        return ret;
	}
    int uniquePaths(int m, int n) 
	{
        // caculate C(m+n-2, m-1) // 不是C(m+n, m)
		int right = n - 1;
        int down = m - 1;
        int total = right + down;
        int ba = max(right,down);
        long long ret = factor(total, ba + 1);
        ret /= factor(total - ba);
        return ret;
    }
	
	int uniquePathsDP(int m, int n) 
	{
        if (m == 0 || n == 0)
            return 0;
            
        vector< vector<int> > path(m, vector<int>(n));
        for (int i = 0; i < m; ++i)
            path[i][0] = 1;
        for (int j = 0; j < n; ++j)
            path[0][j] = 1;
        
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                path[i][j] = path[i-1][j] + path[i][j-1];
            }
        }
        return path[m-1][n-1];
    }
};