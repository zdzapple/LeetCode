class Solution 
{
public:
    int climbStairs(int n) 
	{
		int stairs[1000];
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;
		for (int i = 0; i < 1000; ++ i)
			stairs[i] = 0;
		stairs[1] = 1;
		stairs[2] = 2;
		for (int i = 3; i <= n; ++ i) {
			stairs[i] = stairs[i - 1] + stairs[i - 2];
		}
		return stairs[n];
		// return climbStairs(n - 1) + climbStairs(n - 2);
		
    }
};