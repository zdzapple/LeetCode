class Solution 
{
public:
	int trap(int A[], int n)
	{
		if (n == 0)
			return 0;
		int rain = 0;
		vector<int> rightMaxHeight(n, 0); 
		vector<int> leftMaxHeight(n, 0);
		int maxHeight = 0;
		for (int i = 0; i < n; ++ i)
		{
			leftMaxHeight[i] = maxHeight;
			maxHeight = max(maxHeight, A[i]);
		}
		maxHeight = 0;
		for (int i = n - 1; i >= 0; -- i)
		{
			rightMaxHeight[i] = maxHeight;
			maxHeight = max(maxHeight, A[i]);
		}
		for (int i = 0; i < n; ++ i)
		{
			int water = min(leftMaxHeight[i], rightMaxHeight[i]) - A[i];
			rain += water > 0 ? water : 0;
		}
		return rain;
	}


    int trap1(int A[], int n) // TLE
	{
        if (n == 0)
			return 0;
		int rain = 0;
		int topest = 0;
		for (int i = 0; i < n; ++ i)
		{
			if (A[i] > topest) {
				topest = A[i];
			}
		}
		for (int k = 0; k < topest; ++ k)
		{
			int start = 0, end = n - 1;
			while (start < n && A[start] == 0)
				start ++;
			while (end >= 0 && A[end] == 0)
				end --;
			if (start >= end) {
				break;
			}
			int begin = start;	
			for (int i = start; i <= end; ++ i)
			{
				if (A[i] > 0) {
					rain += (i - begin);
					begin = i + 1;
					A[i] --;
				}
			}
			
		}
		return rain;
        
    }
};