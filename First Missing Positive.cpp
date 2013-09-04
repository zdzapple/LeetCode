class Solution 
{
public:
	int firstMissingPositive(int A[], int n) 
	{
		if (n <= 0)
			return 1;
		// the result should be no more than n+1
		for (int i = 0; i < n; ++ i)
		{
			if (A[i] > 0 && A[i] < n + 1) {
				if (A[i] - 1 != i && A[A[i] - 1] != A[i]) { // case: [1, 1]
				// put A[i] to the right place
					int temp = A[A[i] - 1];
					A[A[i] - 1] = A[i];
					A[i] = temp;
					i --;
				}
			}
		}
		for (int i = 0; i < n; ++ i)
		{
			if (A[i] != i + 1)
				return i + 1;
		}
		return n + 1;
	}
	
/**
Linear time usually requires hash table to do search in constant time, constant space requires we use a fixed number of variables or we directly use the input memory. Here constant space means the second case. So basically we use the input array A[] as our hash table, and by one pass through the whole array, we put each number a >= 1 and a <= n into the right position, that is a should be in position a-1, the key observation is that, the first missing positive could only be 1,….n, n+1, so basically we try to set all these positions in A to contain the right number, after this is done, we check the first slot where the position does not contain the right number, this position + 1 is the first missing positive. We can use swap or something else to do the thing that we set the position to contain the right number.

// 我想到了使用类似于计数排序的思路，当没想到result不会大于n+1
**/
	
    int firstMissingPositiveError(int A[], int n) 
	{
		// case: [1000, -1]
        if (n <= 0)
			return 1;
		int sum = 0;
		int maxNum = 0;
		map<int, bool> isExist;
		for (int i = 0; i < n; ++ i)
		{
			if (A[i] > 0) {
				if (isExist.find(A[i]) == isExist.end()) {
					sum += A[i];
					maxNum = max(maxNum, A[i]);
					isExist[A[i]] = true;
				}
			}
		}
		for (int i = 1; i <= maxNum; ++ i)
			sum -= i;
		if (sum < 0)
			return -sum;
		else
			return maxNum + 1;
        
    }
};