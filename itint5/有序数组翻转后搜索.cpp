int search(vector<int> &arr, int start, int end, int target)
{
	if (start > end)
		return -1;
	int mid = (start + end) / 2;
	if (arr[mid] == target)
		return mid;
	if (arr[mid] >= arr[start]) {
		if (target >= arr[start] && target <= arr[mid])
			return search(arr, start, mid - 1, target);
		else
			return search(arr, mid + 1, end, target);
	} else {
		if (target >= arr[mid] && target <= arr[end])
			return search(arr, mid + 1, end, target);
        
		else
		    return search(arr, start, mid - 1, target);	
	}
	return -1;
}

int search(vector<int> &arr, int target)
{
	if (arr.empty())
		return -1;
	return search(arr, 0, arr.size() - 1, target);
}