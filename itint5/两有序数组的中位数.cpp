double findKth(vector<int> &a, int m, int start1, vector<int> &b, int n, int start2, int k)
{
	// always assume m <= n
	if (m > n)
		return findKth(b, n, start2, a, m, start1, k);
	if (m == 0)
		return b[start2 + k - 1];
	if (k == 1)
		return min(a[start1], b[start2]);
	
	int pa = min(m, k / 2);
	int pb = k - pa;
	if (a[start1 + pa - 1] < b[start2 + pb - 1])
		return findKth(a, m - pa, start1 + pa, b, n, start2, k - pa);			
	else if (a[pa - 1] > b[pb - 1])
		return findKth(a, m, start1, b, n - pb, start2 + pb, k - pb);
	else
		return a[start1 + pa-1];
		
}


int median(vector<int> &arr1, vector<int> &arr2) 
{
	int totalSize = arr1.size() + arr2.size() ;
	if (totalSize % 2 == 0) 
		return (findKth(arr1, arr1.size(), 0, arr2, arr2.size(), 0, totalSize / 2) 
				+ findKth(arr1, arr1.size(), 0, arr2, arr2.size(), 0, totalSize / 2 + 1)) / 2;
	return findKth(arr1, arr1.size(), 0, arr2, arr2.size(), 0, totalSize / 2 + 1);
}

int findKth(int a[], int m, int b[], int n, int k)
	{
		// always assume m <= n
		if (m > n)
			return findKth(b, n, a, m, k);
		if (m == 0)
			return b[k-1];
		if (k == 1)
			return min(a[0], b[0]);
		
		int pa = min(m, k / 2);
		int pb = k - pa;
		if (a[pa - 1] < b[pb - 1])
			return findKth(a + pa, m - pa, b, n, k - pa);			
		else if (a[pa - 1] > b[pb - 1])
			return findKth(a, m, b + pb, n - pb, k - pb);
		else
			return a[pa-1];
			
	}
	
    int median(vector<int> &arr1, vector<int> &arr2) 
    {
        int m = arr1.size();
        int n = arr2.size();
        int *A = new int[m];
        int *B = new int[n];
        for (int i = 0; i < m; ++ i)
            A[i] = arr1[i];
        for (int j = 0; j < n; ++ j)
            B[j] = arr2[j];
		int total = (m + n);
		if (total & 0x01) {
			return findKth(A, m, B, n, total / 2 + 1);
		} else {
			return (findKth(A, m, B, n, total / 2) + findKth(A, m, B, n, total / 2 + 1)) / 2;
		}
    }

