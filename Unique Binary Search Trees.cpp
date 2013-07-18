class Solution 
{
public:
    int numTrees(int n) 
	{
        if (n <= 0)
			return 0;
		vector<int> num(n+1, 0);
		num[0] = 1;
		num[1] = 1;
		num[2] = 2;
		for (int i = 3; i <= n; ++ i)
		{
			for (int j = 0; j <= i-1; ++ j) 
			{
				num[i] += num[j] * num[i-j-1];
			}
		}
        return num[n];
    }
};