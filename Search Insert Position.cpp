class Solution 
{
public:
    int searchInsert(int A[], int n, int target) 
	{
        if (n == 0)
			return 0;
		int left = 0; 
		int right = n - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (A[mid] == target)
				return mid;
			if (A[mid] < target)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return left;
        
    }
};