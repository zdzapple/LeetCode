/**
I	1
V	5
X	10
L	50
C	100
D	500
M	1,000

the numeral I can be placed before V and X to make 4 units (IV) and 9 units (IX) respectively
X can be placed before L and C to make 40 (XL) and 90 (XC) respectively
C can be placed before D and M to make 400 and 900 according to the same pattern CD CM
**/
class Solution 
{
public:
    int romanToInt(string s) 
	{
        int result = 0;
		int i;
		int n = s.size();
		for (i = 0; i < s.size(); ++ i)
		{
			switch (s[i])
			{
			case 'M': 
				result += 1000;
				break;
			case 'D':
				result += 500;
				break;
			case 'C':
				if (i + 1 <= n-1 && s[i+1] == 'D') {
					result += 400;
					i ++;
				} else if (i + 1 <= n-1 && s[i+1] == 'M') {
					result += 900;
					i ++;
				} else
					result += 100;
				break;
			case 'L':
				result += 50;
				break;
			case 'X':
				if (i + 1 <= n-1 && s[i+1] == 'L') {
					result += 40;
					i ++;
				} else if (i + 1 <= n-1 && s[i+1] == 'C') {
					result += 90;
					i ++;
				} else
					result += 10;
				break;
			case 'V':
				result += 5;
				break;
			case 'I':
				if (i + 1 <= n-1 && s[i+1] == 'V') {
					result += 4;
					i ++;
				} else if (i + 1 <= n-1 && s[i+1] == 'X') {
					result += 9;
					i ++;
				} else
					result += 1;
				break;
			}
		}
		return result;
        
    }
};