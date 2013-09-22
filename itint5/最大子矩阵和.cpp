int maxConsSum(const vector<int> &arr) 
{
	int n = arr.size();
	if (n == 0)
		return 0;
	int maxSum = arr[0];
	int curSum = arr[0];
	for (int i = 1; i < n; ++ i)
	{
		if (curSum > 0)
			curSum += arr[i];
		else
			curSum = arr[i];
		if (maxSum < curSum)
			maxSum = curSum;
	}
	return maxSum > 0 ? maxSum : 0;
}

int maxRectSum(vector<vector<int> > &matrix) 
{
	int maxSum = 0;
	if (matrix.empty())
		return 0;
	for (int i = 0; i < matrix.size(); i ++)
	{
		vector<int> subMatrix(matrix[0].size(), 0);
		for (int j = i; j < matrix.size(); ++ j)
		{
			for (int k = 0; k < matrix[0].size(); ++ k)
			{
				subMatrix[k] += matrix[j][k];
			}
		}
		maxSum = max(maxSum, maxConsSum(subMatrix));
	}
	return maxSum;
}