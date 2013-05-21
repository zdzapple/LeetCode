class Solution 
{
public:
    void merge(int A[], int m, int B[], int n) 
	{
		int i, j;
		vector<int> tempA(A, A + m);
		i = 0, j = 0;
		int index = 0;
		while (i < m && j < n) 
		{
			if (tempA[i] <= B[j]) {
				A[index ++] = tempA[i ++];
			}
			else 
				A[index ++] = B[j ++];
		}
		if (i < m) {
			while (i < m)
				A[index ++] = tempA[i ++];
		} else if (j < n)
			while (j < n)
				A[index ++] = B[j ++];
    }
};