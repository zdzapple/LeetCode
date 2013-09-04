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

/**
bool isNumber(const char *s) {
    enum InputType {
        INVALID,    // 0
        SPACE,      // 1
        SIGN,       // 2
        DIGIT,      // 3
        DOT,        // 4
        EXPONENT,   // 5
        NUM_INPUTS  // 6
    };
    int transitionTable[][NUM_INPUTS] = {
        -1,  0,  3,  1,  2, -1,     // next states for state 0
        -1,  8, -1,  1,  4,  5,     // next states for state 1
        -1, -1, -1,  4, -1, -1,     // next states for state 2
        -1, -1, -1,  1,  2, -1,     // next states for state 3
        -1,  8, -1,  4, -1,  5,     // next states for state 4
        -1, -1,  6,  7, -1, -1,     // next states for state 5
        -1, -1, -1,  7, -1, -1,     // next states for state 6
        -1,  8, -1,  7, -1, -1,     // next states for state 7
        -1,  8, -1, -1, -1, -1,     // next states for state 8
    };

int state = 0;
while (*s != '\0') {
    InputType inputType = INVALID;
    if (isspace(*s))
        inputType = SPACE;
    else if (*s == '+' || *s == '-')
        inputType = SIGN;
    else if (isdigit(*s))
        inputType = DIGIT;
    else if (*s == '.')
        inputType = DOT;
    else if (*s == 'e' || *s == 'E')
        inputType = EXPONENT;

    // Get next state from current state and input symbol
    state = transitionTable[state][inputType];

    // Invalid input
    if (state == -1) return false;
    else ++s;
}
// If the current state belongs to one of the accepting (final) states,
// then the number is valid
return state == 1 || state == 4 || state == 7 || state == 8;

}



**/
