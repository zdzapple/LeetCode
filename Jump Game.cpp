class Solution 
{
public:
    bool canJump(int A[], int n) 
	{
        if (n <= 0)
			return false;
		vector<bool> reachable(n, false);
		if (n == 1)
			return true;
		if (A[0] == 0 && n > 1)
			return false;
        for (int i = n-1; i > 0; -- i)
		{
			if (A[i-1] > 0) {
				reachable[i] = true;
			} else {
				for (int j = i - 2; j >= 0; -- j)
				{
					if (A[j] >= i - j) {
						reachable[i] = true;
						// also can reach the index between them
						for (int k = i; k >= j + 1; -- k)
							reachable[k] = true;
						i -= (i-j-1);
						break;
					}
				}
				if (!reachable[i])
					return false;
			}
		}
		return true;
    }
};

/**
一维DP，定义 jump[i]为从index 0 走到第i步时，剩余的最大步数。
转移方程
 jump[i] = max(jump[i-1], A[i-1]) -1, i!=0  
         = 0 , i==0  

	bool canJump(int A[], int n) 
	{  
		int* jump = new int[n];  
		jump[0] = 0;  
		for(int i=1; i < n; i++)  
		{  
			jump[i] = max(jump[i-1], A[i-1]) -1;  
			if(jump[i] < 0)  
				return false;;  
		}  
		return jump[n-1] >=0;  
    }  
*/

/**
Greedy: use a variable to keep the current maximum reachable distance from zero position, linear scan the given array, and update the maximum reachable distance by comparing with A[i] + i, once the maximum reachable distance is larger than the length of the array, return true, after linear scanning, the maximum reachable distance is not larger than the length, we return false.

class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (n == 1)
            return true;

        int i , cur_max = 0 , target = n-1;

        for (i=0 ; i<n-1; ++i)
        {
            if (A[i] == 0 && cur_max < i+1)
                return false;

            if (A[i] + i > cur_max && A[i]>0)
            {
                cur_max = i + A[i];

                if (cur_max >= target)
                    return true;
            }
        }
        return false;
    }
};



**/