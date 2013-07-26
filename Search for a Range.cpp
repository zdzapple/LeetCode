class Solution 
{
public:
    vector<int> searchRange(int A[], int n, int target) 
	{
        vector<int> result(2, -1);
        if (0 == n) 
			return result;
        if (A[0] > target) 
			return result;
        if (A[n-1] < target) 
			return result;
        // search for the lower bound
		int left = 0; 
		int right = n - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (A[mid] < target)
				left = mid + 1;
			else
				right = mid - 1;
		}
		if (A[left] != target)
            return result;
		result[0] = left;
		// find for the upper bound
		right = n - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (A[mid] > target)
				right = mid - 1;
			else
				left = mid + 1;
		}
		result[1] = right;
		return result;
			
    }
};