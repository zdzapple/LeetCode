class Solution 
{
public:
#define RED 0  
#define WHITE 1  
#define BLUE 2 
	inline void swap(int &a, int &b)
	{
        int temp = a;
        a = b;
        b = temp;
    }
	
    void sortColors(int A[], int n)
	{
		if (n <= 0)
			return;
		int redIndex = 0;
		int blueIndex = n - 1; // pointer to the blue color should put
								// if we use whiteIndex, we may swap a lot
		int cur = 0;
		for (; cur <= blueIndex; )
		{
			if (A[cur] == RED) {
				swap(A[redIndex], A[cur]);
				redIndex ++;
				cur = (cur <= redIndex) ? redIndex : cur;
			} else if (A[cur] == WHITE) {
				cur ++;
			} else {
				swap(A[cur], A[blueIndex]);
				blueIndex --;
			}
		}
	}
};