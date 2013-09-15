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