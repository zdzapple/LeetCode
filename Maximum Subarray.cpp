class Solution 
{
public:
// Divide and Conquer
	int maxSubArray(int A[], int begin, int end)
	{
		if (begin == end)
			return A[begin];
		int mid = (begin + end) / 2;
		int leftMax = maxSubArray(A, begin, mid);
		int rightMax = maxSubArray(A, mid+1, end);
		int middleMax = getCrossMax(A, begin, mid, end);
		return max(leftMax, max(rightMax, middleMax));
	}
	
	int getCrossMax(int A[], int begin, int mid, int end)
	{
		int leftMax = A[mid]; // if INT_MIN add a negetive integer, it overflow.
		int rightMax = A[mid+1];
		int sum = 0;
		for (int i = mid; i >= begin; -- i)
		{
			sum += A[i];
			if (leftMax < sum)
				leftMax = sum;
		}
		sum = 0;
		for (int i = mid + 1;  i <= end; ++ i)
		{
			sum += A[i];
			if (rightMax < sum)
				rightMax = sum;
		}
		return leftMax + rightMax;
	}
	
    int maxSubArrayDivideAndConquer(int A[], int n) 
	{
        if (n == 1)
			return A[0];
		return maxSubArray(A, 0, n-1);
        
    }
	/* --- DP----- */
	// dp[i] = maxSumArray of A[0...i]
	int maxSubArray(int A[], int n) 
	{
		if (n == 1)
			return A[0];
		vector<int> dp(n, INT_MIN);
		dp[0] = A[0];
		int maxSub = dp[0];
		for (int i = 1; i < n; ++ i)
		{
			dp[i] = max(A[i], dp[i-1]+A[i]);
			if (maxSub < dp[i])
				maxSub = dp[i];
		}
		
		return maxSub;
	}
};