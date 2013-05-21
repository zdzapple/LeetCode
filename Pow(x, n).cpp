// note: n < 0. Use divide and conquer.
class Solution 
{
public:
	double pow(double x, int n) 
	{
        if (n == 0)
			return 1;
		if (n == 1)
			return x;
		double result;
		int nn = abs(n);
		double v = pow(x, nn / 2);
		if (nn % 2 == 0)
			result = v * v;
		else
			result = x * v * v;
		if (n < 0)
			return 1.0 / result;
		return result;
    }
	
	// non-recursive version
	// x^n = x^(n/2) * x^(n/2) * x^(n%2)
	/**
		考虑x^23，可以先从x ->x^2 -> x^4 -> x^8 -> x^16 取result1 = x^16，然后23-16=7。
		我们只要计算x^7再与result1相乘就可以得到x^23。对于x^7也可以采用这种方法
		取result2 = x^4，然后7-4=3，只要计算x^3再与result2相乘就可以得到x^7。由此可以将x^23写成x^16 * x^4* x^2 * x，即23=16+4+2+1，而23 = 10111(二进制)，所以只要将n化为二进制并由低位到高位依次判断如果第i位为1，则result *=x^(2^i)。
	**/
	double pow1(double x, int n)
	{
		if (n == 0)
			return 1;
		if (n == 1)
			return x;
		if (x == 0)
			return 0;
		bool isNegetive = (n < 0) ? true : false;
		n = abs(n);
		double result = 1.0;
		while (n > 0) // don't use 'while(n)'
		{
			if (n & 1)
				result *= x;
			x *= x;
			n >>= 1;
		}
		if (isNegetive)
			return 1.0 / result;
		else
			return result;
	}
};