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

    int search(int A[], int n, int target) 
	{
        if (n <= 0)
			return -1;
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
				result = binarySearch(A, pivotIndex + 1, n - 1, target);
		}
		return result;
        
    }
};

/**
//use binary search to find the rotated index;

int FindSortedArrayRotation(int A[], int N) {
  int L = 0;
  int R = N - 1;
  
  while (A[L] > A[R]) {
    int M = L + (R - L) / 2;
    if (A[M] > A[R])
      L = M + 1;
    else
      R = M;
  }
  return L;
}
**/

/**
int rotated_binary_search(int A[], int N, int key) {
  int L = 0;
  int R = N - 1;
 
  while (L <= R) {
    // Avoid overflow, same as M=(L+R)/2
    int M = L + ((R - L) / 2);
    if (A[M] == key) return M;
 
    // the bottom half is sorted
    if (A[L] <= A[M]) {
      if (A[L] <= key && key < A[M])
        R = M - 1;
      else
        L = M + 1;
    }
    // the upper half is sorted
    else {
      if (A[M] < key && key <= A[R])
        L = M + 1;
      else 
        R = M - 1;
    }
  }
  return -1;
}

**/