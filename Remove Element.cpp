class Solution 
{
public:
    int removeElement(int A[], int n, int elem) 
	{
        if (n <= 0)
			return n;
		int result = 0;
		for (int i = 0; i < n; ++ i)
		{
			if (A[i] != elem) {
				A[result ++] = A[i];
			}
		}
		return result;
    }
};