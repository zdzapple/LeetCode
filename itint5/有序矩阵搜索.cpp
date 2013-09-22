bool exists(vector<vector<int> > &matrix, int target) 
{
	if (matrix.empty())
		return false;
	int m = matrix.size();
	int n = matrix[0].size();
	if (target < matrix[0][0] || target > matrix[m-1][n-1])
		return false;
	int row = 0, col = n - 1;
	while (row <= m - 1 && col >= 0)
	{
		if (target > matrix[row][col])
			row ++;
		else if (target < matrix[row][col])
			col --;
		else
			return true;
	}
	return false;
}