#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s)
	{
        stack<char> st;
		string::iterator it;
		for (it = s.begin(); it != s.end(); ++ it)
		{
			char ch = *it;
			if (ch == '(' || ch == '[' || ch == '{') {
				st.push(ch);
			} else {
				if (st.empty()) // important!!
					return false;
				char top = st.top();
				if (isClosedBrackets(top, ch))
					st.pop();
				else
					return false;
			}
		}
		if (st.empty())
			return true;
		return false;
    }

	bool isClosedBrackets(char left, char right)
	{
		if ((left == '(' && right == ')')
				|| (left == '[' && right == ']')
				|| (left == '{' && right == '}'))
			return true;
		return false;
	}
};

int main()
{
	stack<int> s;
	int i = s.top();
	cout <<  i << endl;
}
