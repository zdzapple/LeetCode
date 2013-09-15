void traverse(vector<int> &arr, int begin, int end)
{
	int len = end - begin + 1;
	for (int i = 0; i < len / 2; ++ i)
	{
		swap(arr[begin], arr[end]);
		begin ++;
		end --;
	}
}

bool next_permutation(vector<int> &arr) 
{
	int size = arr.size();
	int i, j;
	for (i = size - 1; i >= 1; -- i)
	{
		if (arr[i-1] < arr[i])
			break;
	}
	if (i < 1)
		return false;
	i --;
	// find the min number that greater than arr[i]
	for (j = size - 1; j > i; -- j)
		if (arr[j] > arr[i])
			break;
	swap(arr[i], arr[j]);
	// traverse the numbers behinde arr[i]
	traverse(arr, i+1, size-1);
	return true;
}