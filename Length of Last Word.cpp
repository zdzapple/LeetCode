class Solution 
{
public:
    int lengthOfLastWord(const char *s) 
	{
        int n = strlen(s);
		if (s == NULL)
			return 0;
		const char *p = s + n - 1;
		int len = 0;
		while (*p == ' ' && n > 0) { // special case~
			p --;
			n --;
		}
		for (int i = 0; i < n; ++ i)
		{
			if (*p == ' ')
				return len;
			p --;
			len ++;
		}
		return len;
        
    }
};