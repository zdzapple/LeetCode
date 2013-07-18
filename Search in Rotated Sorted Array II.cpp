class Solution 
{
public:
	int binarySearch(int A[], int start, int end, int target)
	{
		int mid = -1;
		while (start <= end)
		{
			mid = start + (end - start) / 2;
			if (A[mid] == target)
				return mid;
			if (A[mid] < target) {
				start = mid + 1;
			} else {
				end = mid - 1;
			}
		}
		return -1;
	}

    bool search(int A[], int n, int target) 
	{
        if (n <= 0)
			return false;
		int pivotIndex = -1;
		for (int i = 0; i < n-1; ++ i)
		{
			if (A[i+1] < A[i]) {
				pivotIndex = i;
			}
		}
		int result;
		if (pivotIndex == -1) {
			result = binarySearch(A, 0, n-1, target);
		} else {
			result = binarySearch(A, 0, pivotIndex, target);
			if (result == -1)
				result = binarySearch(A, pivotIndex+1, n-1, target);
		}
		return result == -1 ? false : true;
        
    }
};