#include <iostream>
#include <limits.h>
using namespace std;
/**
* how to jude out of range?
*
**/
class Solution
{
public:
	bool isDigit(char ch)
	{
		if (ch >= '0' && ch <= '9')
			return true;
		return false;
	}

    int atoi(const char *str)
	{
		int sign = 1; // 1 - plus, -1 - minus
		if (*str == '\0')
			return 0;
		while (*str != '\0' && *str ==' ') // isspace
			str ++;
		if (*str == '\0')
			return 0;
		if (!isDigit(*str)) {
			if (*str == '+')
				sign = 1;
			else if (*str == '-')
				sign = -1;
			else {
				return 0;
			}
			str ++;
		}
		int result = 0;
		while (*str != '\0' && isDigit(*str)) {
			int temp = *str - '0';
			if (result > (INT_MAX  - temp) / 10) {// out of range
				result = (sign == 1 ? INT_MAX  : INT_MIN );
				return result;
			}

			result *= 10;

			result += temp;
			str ++;
		}

		return result * sign;

    }
};

int main()
{
    char* str = "+1";
    Solution s;
    cout << s.atoi((str)) << endl;
    return 0;
}
