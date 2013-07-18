class Solution 
{
public:
    int removeDuplicates(int A[], int n) 
    {
        if (n <= 0)
			return 0;
		int p, q;
		q = 0;
		int next = 1;
		while (q <= n-1)
		{
			while (next < n && A[next] == A[q])
				next ++;
			q ++;
			if (next < n)
				A[q] = A[next];
            else 
                break;
			
		}
		return q;
		// better way
		/*
		if (n < 2) return n;
        int len = 1;
        for(int i = 1; i < n; ++i) 
		{
            if(A[i] != A[len - 1]) 
			{
                A[len++] = A[i];
            }
        }
        return len;*/
    }
	
};