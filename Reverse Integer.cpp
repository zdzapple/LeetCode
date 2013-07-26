class Solution 
{
public:
    int reverse(int x) 
	{
        if (x == 0)
			return 0;
		bool sgin = x < 0 ? true : false;
		x = x < 0 ? -x : x;
		int result = 0;
		while (x > 0)
		{
			result = result * 10 + x % 10;
			x /= 10;
		}
        if (result < 0)
			return -1;
		if (sgin)
			result = -result;
		return result;
    }
};

/**
if use a string to reverse the integer, the last digit is 0 should be considered.

**/