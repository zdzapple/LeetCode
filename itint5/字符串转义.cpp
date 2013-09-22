void escapeSpace(char *str) 
{
	if (str == NULL || *str == '\0')
		return;
	int n = 0;
	char *p = str;
	int spaceNumber = 0;
	while (*p != '\0')
	{
		if (*p == ' ')
			spaceNumber ++;
		p ++;
		n ++;
	}
	int newLen = n + 2 * paceNumber ;
	if (spaceNumber == 0)
		return;
	p --;
	char *newStr = str + newLen - 1;
	while (spaceNumber > 0)
	{
		if (*p != ' ')
			*newStr = *p;
		else {
			spaceNumber --;
			*newStr = '0';
			newStr --;
			*newstr = '2';
			newStr --;
			*newStr = '%';
		}
		newStr --;
		p --;
		
	}
}