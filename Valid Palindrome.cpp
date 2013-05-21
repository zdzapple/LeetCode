class Solution 
{
public:
	bool isCharacter(char ch)
	{
		if ((ch >= 'a' && ch <= 'z') ||
				(ch >= 'A' && ch <= 'Z'))
			return true;
		return false;
	}
    bool isPalindrome(string s) 
	{
		if (s == "")
			return true;
		int i = 0;
		int j = s.size() - 1;
		int len = s.size();
		while (i <= j)  // note: 1. every loop one step  2. 'alphanumeric' contains digit.
		{
			if (!isCharacter(s[i]) && !isdigit(s[i]))
				i ++;
			else if (!isCharacter(s[j]) && !isdigit(s[j]))
				j --;
			else if (tolower(s[i]) != tolower(s[j]))
				return false;
			else {
				i ++;
				j --;
			}
			
		}
		return true;
    }
};