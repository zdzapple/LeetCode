class Solution {
public:
    int removeDuplicates(int A[], int n) 
	{
        if (n < 2) return n;
        int len = 1;
        bool duplicated = false;
        for(int i = 1; i < n; ++ i) 
		{
            if (A[i] != A[len - 1]) {
                A[len++] = A[i];
                duplicated = false;
            } else if (!duplicated) {
                A[len++] = A[i];
                duplicated = true;
            }
        }
        return len;
    }
};