class Solution 
{
public:
	bool isPalindrome(int x) 
	{
		if (x < 0)
			return false;
		int div = 1;
		while (x / div >= 10) 
		{
			div *= 10;
		}        
		while (x != 0) 
		{
			int l = x / div;
			int r = x % 10;
			if (l != r) return false;
			x = (x % div) / 10;
			div /= 100;
		}
		return true;
	}


// http://leetcode.com/2012/01/palindrome-number.html
	long long reverse(int num) 
	{
		assert(num >= 0);   // for non-negative integers only.
		long long rev = 0; // int may be overflow
		while (num != 0) 
		{
			rev = rev * 10 + num % 10;
			num /= 10;
		}
		return rev;
	}

    bool isPalindrome1(int x) 
	{
        if (x < 0)
			return false;
		if (reverse(x) == x)
			return true;
		return false;
        
    }
};