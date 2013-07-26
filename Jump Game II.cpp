class Solution 
{
public:
/**
jumpNum[i] = min(jumpNum[j] + 1), {0<=j<i, i-j <= A[j]}
**/
    int jump1(int A[], int n) // TLE
	{
        if (n <= 1)
			return 0;
		int *jumpNum = new int[n];
		jumpNum[0] = 0;
		for (int i = 1; i < n; ++ i)
		{
			int minJump = INT_MAX;
			for (int j = 0; j < i; ++ j)
			{
				if (A[j] >= i-j && minJump > jumpNum[j]+1) {
					minJump = jumpNum[j] + 1;
				}
			}
			jumpNum[i] = minJump;
		}
        return jumpNum[n-1];
    }
	
	int jump2(int A[], int n) // TLE
	{
        if (n <= 1)
			return 0;
		vector<int> jumpNum(n, INT_MAX);
		jumpNum[0] = 0;
		for (int i = 0; i < n; ++ i)
		{
			for (int j = i+1; j-i <= A[i] && j < n; ++ j)
			{
				jumpNum[j] = min(jumpNum[i]+1, jumpNum[j]);
			}
			
		}
        return jumpNum[n-1];
	}
	// 贪心策略
	int jump(int A[], int n)
	{
		if (n <= 1)
			return 0;
		int begin, end;
		begin = 0;
		end = 0;
		int steps = 0;
		while (end < n)
		{
			steps ++;
			int max = 0;
			for (int i = begin; i <= end; i++)
			{
				if (A[i] + i >= n-1)
					return steps;
				if (A[i] + i > max)
					max = A[i] + i;
			}
			begin = end + 1;
			end = max;
			
		}
	}
	/**
	二指针问题，最大覆盖区间。
从左往右扫描，维护一个覆盖区间，每扫过一个元素，就重新计算覆盖区间的边界。比如，开始时区间[start, end], 遍历A数组的过程中，不断计算A[i]+i最大值（即从i坐标开始最大的覆盖坐标），并设置这个最大覆盖坐标为新的end边界。而新的start边界则为原end+1。不断循环，直到end> n.
	**/
};
