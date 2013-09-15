class Solution 
{
public:
	bool isMatch(const char *s, const char *p) 
	{  // p每遇到一个*，就保留住当前*的坐标和s的坐标，然后s从前往后扫描，如果不成功，则s++,重新扫描
		bool star = false;  
		const char *str, *ptr;  
		for (str = s, ptr = p; *str != '\0'; str ++, ptr ++)  
		{  
			switch (*ptr)  
			{  
				case '?':  
					break;  
				case '*':  
					star = true;  
					s = str, p = ptr;  
					while (*p == '*')  
						p ++;  
					if (*p == '\0') // 如果'*'之后，pat是空的，直接返回true  
						return true;  
					str = s - 1;  
					ptr = p - 1;  
					break;  
				default:  
				{  
					if (*str != *ptr)  
					{  
						// 如果前面没有'*'，则匹配不成功  
						if (!star)  
							return false;  
						s ++;  
						str = s - 1;  
						ptr = p - 1;  
					}  
				}  
			}  
		}  
		while (*ptr == '*')  
			ptr ++;  
		return (*ptr == '\0');  
	}  


	bool isMatch2(const char *s, const char *p) 
	{
		if (*s == '\0' && *p == '\0')
			return true;
		if (*s == '\0' && *p != '\0') {
			if (*p != '*')
				return false;
			if (*(p + 1) == '\0')
				return true;
			// else return false; case: "ho" "ho**"
			else {
				const char *q = p + 1;
				while (*q == '*' && *q != '\0')
					q ++;
				if (*q != '\0')
					return false;
				return true;
			}
		} 
		if (*s != '\0' && *p == '\0')
			return false;
		// dp[i][j] = isMatch(s[0..i], p[0..j]);
		// note: how to Initialization dp[][]
		int m = strlen(s);
		int n = strlen(p);
		int np_max = 0;
		int star_num = 0;
        const char* pp = p;
        while (*pp) 
		{
			if (*pp != '*') 
				++ np_max; 
			else
				++ star_num;
			++ pp;
		}
        if (m < np_max) return false;
		if (star_num == 0 && m > np_max) // "aa" "a"
			return false;
		
		vector<vector<int> > dp(m + 1, vector<int>(n + 1, false));
		//for (int i = 0; i <= m; ++ i)
		//	dp[i][0] = true;
		int index = 1;
		pp = p;
		while (*pp == '*') // case: "abc" "**c"
		{
			for (int i = 0; i <= m; ++ i)
				dp[i][index] = true; // "c" "*?*"
			pp ++;
			index ++;
		}
		for (int i = 1; i <= m; ++ i)
		{
			for (int j = 1; j <= n; ++ j)
			{
				char sc = *(s+i-1);
				char qc = *(p+j-1);
				if (qc != '*' && qc != '?') {
					dp[i][j] = dp[i-1][j-1] && (sc == qc);
					if (i == 1 && j == 1)
						dp[i][j] = sc == qc;
				} else if (qc == '?') {
					dp[i][j] = dp[i-1][j-1];
					if (i == 1 && j == 1)
						dp[i][j] = true;
				} else {
					// '*'
					if (!dp[i][j])						
					for (int k = i; k >= 1; -- k)
					{	
						if (dp[k][j-1]) {
							dp[i][j] = true;
							break;
						}
					}
				}
			}
		}
		return dp[m][n];
	}



	// TLE case: "ab" "a**************************b"
    bool isMatch1(const char *s, const char *p) 
	{
		if (*s == '\0' && *p == '\0')
			return true;
		if (*s == '\0' && *p != '\0') {
			if (*p != '*')
				return false;
			if (*(p + 1) == '\0')
				return true;
			// else return false; case: "ho" "ho**"
			else {
				const char *q = p + 1;
				while (*q == '*' && *q != '\0')
					q ++;
				if (*q != '\0')
					return false;
				return true;
			}
		}
		if (*s != '\0' && *p == '\0') 
			return false;
		if (*p == '?')
			return isMatch(s + 1, p + 1);
		if (*p == '*') {
			const char *q = p + 1;
			while (*q == '*')
				q ++;
			if (*q == '\0')
				return true;
			const char *m = s;
			while (*m != '\0') 
			{
				if (*m != *q && *q != '?') {
					m ++;
					continue;
				}
				if (isMatch(m, q))
					return true;
				m ++;
			}
			return false;
			/*
			while (true)
			{
				// don't forget *q == '?'. case: "c" "*?*"
				while (*q != *m && *m != '\0') 
					m ++;
				if (*m == '\0')
					return false;
				if (
				if (isMatch(m + 1, q + 1))
					return true;
				m ++;				
			}*/
		}
		if (*s == *p)
			return isMatch(s + 1, p + 1);
		return false;
        
    }
};
/**
贪心：
只需要依据连续的’*'，将p分割成一些不带’*'的子串。然后在s中依次匹配就好了，只不过需要特殊照顾一下首尾两个子串：
1.对于开头不是’*'的p，第一个子串必须从s[0]开始匹配
2.对于结尾不是’*'的p，最后一个子串必须在s的尾巴上匹配


**/
class Solution1 {
public:
    //get pattens splited by '*' or continuous '*'s
    vector<string> getPattens(const char *p) 
	{
        vector<string> ret;
        int ei = 0;
        string *s = NULL;
        while(true) 
		{
            if (p[ei] == '*' || p[ei] == '\0') {
                if (s) {
                    //patten found
                    ret.push_back(*s);
                    delete s;
                    s = NULL;
                }
                if (p[ei] == '\0') break;
            } else {
                if (!s) {
                    s = new string();
                }
                s->push_back(p[ei]);
            }
            ++ ei;
        }
        return ret;
    }
    
    int matchStr(const char *s, string &pat, int basei, int baseilmt) 
	{
        for(; basei <= baseilmt; ++ basei) 
		{
            for (int j = 0; j < pat.size(); ++ j) 
			{
                if (pat[j] != '?' && pat[j] != s[basei + j])
                    break;
                if (j == pat.size() - 1) {
                    return basei;
                }
            }
        }
        return -1;
    }
    
    bool isMatch(const char *s, const char *p) 
	{
        if(s == NULL || p == NULL) return false;
        
        //1. get pattens splited by '*' or continuous '*'s
        vector<string> pattens = getPattens(p);
        if(pattens.size() == 0) {
            if(*p == '*') //p is pure '*'s
                return true;
            else //p is empty
                return *s == '\0';
        }
        
        //2. match each patten one by one on s
        int slen = strlen(s);
        int plen = strlen(p);
        int sb = 0; // begin index of s that we want to search
        bool restrictFront = *p != '*';
        bool restrictRear = p[plen-1] != '*';
        for(int pi = 0; pi < pattens.size() ; ++ pi) 
		{
            string &pat = pattens[pi];
            int sbl = slen - pat.size(); // the last index of s that we want to search
            
            if (sbl < sb) return false;
            
            if (pi == 0 && restrictFront) {
                //first patten may be need to match exactly from 0
                sbl = 0;
            } else if (pi == pattens.size() - 1 && restrictRear) {
                //last patten may be need to match exactly from rear of s
                sb = slen - pat.size();
                sbl = sb;
            }
            
            int matchbase = matchStr(s, pat, sb, sbl);
            if (-1 == matchbase) {
                return false;
            }
            else {
                sb = matchbase + pat.size();
            }
        }
        if (pattens.size() == 1) {
            if (restrictFront && restrictRear) { // p doesn't contain '*'
                return s[sb] == '\0';
            }
            return true;
        }
        return true;
       
    }
};



class Solution {
public:
    bool isMatch(const char *s, const char *p) 
	{
        if (*p == '\0' && *s != '\0')
			return false;
		if (*s == '\0') {
			if (*p == '\0')
				return true;
		}
		const char *q, *k;
		bool isStartExist = false;
		while (*s != '\0')
		{
			if (*s == *p || *p == '?') {
				s ++;
				p ++;
			} else if (*p == '*') {
				while (*p == '*')
					p ++;
				if (*p == '\0')
					return true;
				q = s;
				k = p;
				isStartExist = true;
			} else {
				if (!isStartExist)
					return false;				
				q ++;
				
				s = q;
				p = k;
				/**
				TLE: isMatch(q, p)和下面else的工作一样
				if (isMatch(q, p))
					return true;
				else {
					s = q;
					p = k;
				}
				**/
			}
		}
		while (*p == '*')
			p ++;
		if (*p == '\0')	
			return true;
		return false;
    }
};