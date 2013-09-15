int maxConsSum2(const vector<int> &arr) 
{
	if (arr.empty())
		return 0;
	int n = arr.size();
	int maxSum = arr[0];
	int minSum = arr[0];
	int maxdp = arr[0];
	int mindp = arr[0];
	int sum = arr[0];
	for (int i = 1; i < n; ++ i)
	{
		if (maxdp > 0)
			maxdp += arr[i];
		else
			maxdp = arr[i];
		sum += arr[i];
		if (maxdp > maxSum)
			maxSum = maxdp;
		mindp = min(mindp + arr[i], arr[i]);
		if (mindp < minSum)
			minSum = mindp;
	}
	minSum = min(0, minSum);
	maxSum = max(0, maxSum);
	return max(sum - minSum, maxSum);
}