class Solution 
{
public:
    string intToRoman(int num) 
	{
		char symbol[7] = { 'I','V','X', 'L','C', 'D','M'}; // 1 5 10 50 100 500 1000 
		string result;
		int scale = 1000;
		for (int i = 6; i >= 0; i-=2)
		{
			int digit = num / scale;
			// 1-3/4/5/6-8/9
			if (digit > 0 && digit <= 3) {
				result.append(digit, symbol[i]);
			} else if (digit == 4) {
				result.append(1, symbol[i]);
				result.append(1, symbol[i+1]);
			} else if (digit == 5) {
				result.append(1, symbol[i+1]);
			} else if (digit >= 6 && digit <= 8) {
				result.append(1, symbol[i+1]);
				result.append(digit - 5, symbol[i]);
			} else if (digit == 9) {
				result.append(1, symbol[i]);
				result.append(1, symbol[i+2]);
			}
			num %= scale;
			scale /= 10;
		}
        return result;
    }
};