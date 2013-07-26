class Solution 
{
public:
    vector<vector<int> > generateMatrix(int n) 
	{
		vector<vector<int> > matrix;
		if (n <= 0)
			return matrix;
		for (int i = 0; i < n; ++ i)
		{
			vector<int> v(n, 0);
			matrix.push_back(v);
		}
		
		int times = n / 2;
        if (n % 2 == 1)
			times ++;
		int num = 1;
		for (int t = 0; t < times; ++ t)
		{
			for (int j = t; j < n - t; ++ j)
				matrix[t][j] = num ++;
			for (int j = t + 1; j < n - t; ++ j)
				matrix[j][n-t-1] = num ++;
			if (t + 1 < n - t) // more than one line
				for (int j = n - t - 2; j >= t; -- j)
					matrix[n-t-1][j] = num ++;
			if (t < n - t - 1) // more than one column
				for (int j = n - t - 2; j > t; -- j)
					matrix[j][t] = num ++;
		}
		return matrix;
        
    }
};