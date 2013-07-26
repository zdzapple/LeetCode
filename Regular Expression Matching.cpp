class Solution 
{
public:
    bool isMatch(const char *s, const char *p) 
	{
		if (*p == '\0')
			return *s == '\0';
		// the next character is not '*'
		if (*(p + 1) != '*') {
			return (*s == *p || (*p == '.' && *s != '\0')) && isMatch(s + 1, p + 1);
		}
        // the next character is '*'
		while (*s == *p || (*p == '.' && *s != '\0'))
		{
			if (isMatch(s, p + 2))
				return true;
			s ++;
		}
		
		return isMatch(s, p + 2);
    }
};
/**
正则表达式和通配符不同。
*表示重复前面的字符0~无限次。

http://leetcode.com/2011/09/regular-expression-matching.html

**/