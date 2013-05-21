#include <iostream>
using namespace std;

// special case: 3e3.1 1e+9 2. .2. 2.e1 4e+ .0.39
class Solution
{
public:
    bool isNumber(const char *s)
	{
		const char *p = s;
		int type = 0; // 1 - digit, 2 - exp, 3 - decimal, 4 - space
		if (p == NULL)
			return false;
		while (isspace(*p))
			p ++;
		if (*p != '\0' && (*p == '-' || *p == '+')) {
			p ++;
		}
		if (*p != '\0' && *p == '.') {
            type = 3;
            p ++;
		}
		if (isdigit(*p)) {
			if (type == 0) // .0.04
                type = 1;
			p ++;
			while (*p != '\0') {
               //     cout << *p << endl;
				if (isdigit(*p)) {
					p ++;
					continue;
				}
				if (*p == '.' && type != 0 && type != 3 && type != 2) {
					type = 3;
					p ++;
					if (*p != '\0' && !isdigit(*p) && *p != ' ' && *p != 'e' && *p != 'E')
                        return false;
				} else if ((*p == 'e' || *p == 'E') && type != 0 && type != 2) {
					type = 2;
					p ++;
					if (!isdigit(*p) && *p != '-' && *p != '+') // 1e 1e.
                        return false;
                    else {
                        if (*p == '-' || *p == '+') {
                            p ++;
                            if (!isdigit(*p))
                                return false;
                        }
                    }
				} else if (*p == ' ') {
					type = 4;
					while (p && *p == ' ') {
						p ++;
					}
					if (*p != '\0')
						return false;
					else
						return true;
				} else
					return false;
			}

		} else
			return false;
		return true;
    }

};

int main()
{
    Solution s;
    cout << s.isNumber(".0.39") << endl;
    return 0;
}
