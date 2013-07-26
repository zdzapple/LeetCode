class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) 
	{
        vector<int> result;
		if (matrix.empty())
			return result;
		int m = matrix.size();
		int n = matrix[0].size();
		int beginR, begeinC;
		int times = min(m, n) / 2;
        if (min(m, n) % 2 == 1)
			times ++;
		for (int t = 0; t < times; ++ t)
		{
			for (int j = t; j < n - t; ++ j)
				result.push_back(matrix[t][j]);
			for (int j = t + 1; j < m - t; ++ j)
				result.push_back(matrix[j][n-t-1]);
			if (t + 1 < m - t) // more than one line
				for (int j = n - t - 2; j >= t; -- j)
					result.push_back(matrix[m-t-1][j]);
			if (t < n - t - 1) // more than one column
				for (int j = m - t - 2; j > t; -- j)
					result.push_back(matrix[j][t]);
		}
		return result;
    }
};
/**
要加上判断，要不就会重复
**/
