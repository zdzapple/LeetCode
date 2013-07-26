class Solution 
{
public:
    int divide(int dividend, int divisor) 
	{
        int quotient = 0;
		if (dividend == 0)
			return 0;
		bool isNegative = false;
		if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
			isNegative = true;
		}
		if (abs(divisor) == 1)
			quotient = dividend > 0 ? dividend : -dividend;//abs(dividend); --> abs(INT_MIN) = INT_MIN
		else {
			unsigned int div = dividend > 0 ? dividend : -dividend;//abs(dividend);
			int bit[32];
			int i = 0;
			unsigned int magValue = divisor > 0 ? divisor : -divisor;
			while (magValue > 0 && div >= magValue)
			{
				bit[i] = magValue;
				magValue = magValue << 1;
				i ++;
			}
			-- i;
			while (i >= 0 && div != 0)
			{
				if (div >= bit[i])
				{
					div -= bit[i];
					quotient += 1 << i;
				}
				-- i;
			}
		}
        return isNegative == true ? -quotient : quotient;
    }
};