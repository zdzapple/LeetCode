class Solution 
{
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) 
	{
        if (m == 0 || n == 0)
            return 0;
            
        vector< vector<int> > path(m, vector<int>(n, 0));
		bool obstacle = false;
        for (int i = 0; i < m; ++ i)
		{
			if (obstacleGrid[i][0] == 1) {
				break;
			}
			path[i][0] = 1;
		}
        for (int j = 0; j < n; ++ j)
		{	
            if (obstacleGrid[0][j] == 1) {
				break;
			}
			path[0][j] = 1;
        }
        for (int i = 1; i < m; ++ i)
        {
            for (int j = 1; j < n; ++ j)
            {
				if (obstacleGrid[i][j] == 1)
					path[i][j] = 0;
                else 
					path[i][j] = path[i-1][j] + path[i][j-1];
            }
        }
        return path[m-1][n-1];
        
    }
};