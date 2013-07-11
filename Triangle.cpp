class Solution 
{
public:
    int minimumTotal1(vector<vector<int> > &triangle) 
	{
		if (triangle.empty())
			return 0;
        int rows = triangle.size();
		vector<int> result(triangle.back().size(), 0);
		result[0] = triangle[0][0];
		for (int i = 1; i < rows; ++ i)
		{
			vector<int> row = triangle[i];
			vector<int> tmp(result.begin(), result.end());
			int rowSize = row.size();
			result[0] = tmp[0] + row[0];
			for (int j = 1; j < rowSize - 1; ++ j)
			{
				result[j] = min(tmp[j-1], tmp[j]) + row[j];
			}
			result[rowSize-1] = tmp[rowSize-2] + row.back();
		}
        int minimum = result[0];
		for (int i = 1; i < result.size(); ++ i)
		{
			if (minimum > result[i])
				minimum = result[i];
		}
		return minimum;
    }
	// Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
	int minimumTotal(vector<vector<int> > &triangle) 
	{
		if (triangle.empty())
			return 0;
        int rows = triangle.size();
		vector<int> result(triangle.back().size(), 0);
		result[0] = triangle[0][0];
		for (int i = 1; i < rows; ++ i)
		{
			vector<int> row = triangle[i];
			int tmp = result[0];
			int rowSize = row.size();
			result[0] = result[0] + row[0];
			
			for (int j = 1; j < rowSize - 1; ++ j)
			{
				int tmp1 = result[j];
				result[j] = min(tmp, result[j]) + row[j];
				tmp = tmp1;
			}
			result[rowSize-1] = tmp + row.back();
		}
        int minimum = result[0];
		for (int i = 1; i < result.size(); ++ i)
		{
			if (minimum > result[i])
				minimum = result[i];
		}
		return minimum;
    }
};