class Solution 
{
public:
	/**
	* Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
	**/
	// Time Limit Exceeded
    char *strStr1(char *haystack, char *needle) 
	{ 
		char *p = haystack;
		char *q = needle;
		if (haystack == NULL && needle == NULL)
			return NULL;
		if (*needle == NULL)
			return haystack;
		
		while (*p != '\0')
		{
			if (*p == *q) {
				char *ret = p;
				while (*q != '\0' && *p != '\0' && *p == *q)
				{
					p ++;
					q ++;
				}
				if (*q == '\0')
					return ret;		
				q = needle;
				p = ret;
			}
			p ++;
		}
		return NULL;
        
    }
	
	/**
	** use p1Adv to control the loop times. if loop times > n-m+1, then end the function.
	**/
	char *strStr2(char *haystack, char *needle) 
	{ 
		if (!*needle) return haystack;
		char *p1 = (char*)haystack, *p2 = (char*)needle;
		char *p1Adv = (char*)haystack;
		while (*++p2)
			p1Adv++;
		while (*p1Adv) {
			char *p1Begin = p1;
			p2 = (char*)needle;
			while (*p1 && *p2 && *p1 == *p2) {
				p1++;
				p2++;
			}
			if (!*p2)
				return p1Begin;
			p1 = p1Begin + 1;
			p1Adv++;
		}
		return NULL;
	}
	
	/**
	* KMP algorithm
	**/
	vector<int> computePrefix(char *target)
	{
		int m = strlen(target);
		vector<int> pi(m, 0);
		pi[0] = -1;
		int k = -1;
		for (int q = 1; q < m; ++ q)
		{
			while (k > -1 && target[k + 1] != target[q])
				k = pi[k];
			if (target[k+1] == target[q])
				k ++;
			pi[q] = k;
		}
		return pi;
	}
	
	char *strStr(char *haystack, char *needle) 
	{ 
		if(haystack == NULL || needle == NULL) return NULL;  
		int n = strlen(haystack);
		int m = strlen(needle);
		if (m ==0) return haystack;  
		if (n == 0 ) return NULL;  
		
		vector<int> pi = computePrefix(needle);
		int q = -1;
		for (int i = 0; i < n; ++ i)
		{
			while (q > -1 && needle[q+1] != haystack[i])
				q = pi[q];
			if (needle[q+1] == haystack[i])
				q ++;
			if (q == m - 1)
				return &haystack[i - m + 1];	
		}
		return NULL;
	}
};