class Solution 
{
public:
/**
*就是s1和s2是scramble的话，那么必然存在一个在s1上的长度l1，将s1分成s11和s12两段，同样有s21和s22。
那么要么s11和s21是scramble的并且s12和s22是scramble的；
要么s11和s22是scramble的并且s12和s21是scramble的。
note:  使用搜索/递归，要考虑剪枝
**/
    bool isScramble1(string s1, string s2) 
	{
        if(s1.size() != s2.size()) return false;
        if(s1 == s2) return true;
        string ts1 = s1,ts2 = s2;
		// 不加sort会tle
        sort(ts1.begin(), ts1.end());
        sort(ts2.begin(), ts2.end()); 
		/*int A[26];
		memset(A, 0, sizeof(A) / sizeof(int));
		for (int i = 0; i < s1.size(); ++ i)
			A[s1[i]-'a'] ++;
		for (int i = 0; i < s2.size(); ++ i)
			A[s2[i]-'a'] --;
		for (int i = 0; i < 26; ++ i)
			if (A[i] != 0)
				return false;*/
        if(ts1 != ts2) return false;
        for(int isep = 1; isep < s1.size(); ++ isep) {
            //seporate s1 as [0,isep - 1],[isep, s1.size() - 1]
            string seg11 = s1.substr(0,isep);
            string seg12 = s1.substr(isep);
            {//see if forward order is ok
                string seg21 = s2.substr(0,isep);
                string seg22 = s2.substr(isep);
                if(isScramble(seg11,seg21) && isScramble(seg12,seg22)) return true;
            }
            {//see if reverse order is ok
                string seg21 = s2.substr(s2.size() - isep);
                string seg22 = s2.substr(0,s2.size() - isep);
                if(isScramble(seg11,seg21) && isScramble(seg12,seg22)) return true;
            }
        }
        return false;
    }
	
	/**
	使用DP，很大程度上可以减少递归过程中的重复运算，保存中间结果
	
	dp[i][j][k] 代表了s1从i开始，s2从j开始，长度为k的两个substring是否为scramble
string。

有三种情况需要考虑：

1. 如果两个substring相等的话，则为true

2. 如果两个substring中间某一个点，左边的substrings为scramble string，
同时右边的substrings也为scramble string，则为true

3. 如果两个substring中间某一个点，s1左边的substring和s2右边的substring为scramble
string, 同时s1右边substring和s2左边的substring也为scramble
string，则为true
	**/
	bool isScramble(string s1, string s2) 
	{
		if(s1.size() != s2.size()) return false;
        if(s1.size() == 0) return true;
        if(s1 == s2) return true;
		bool ***dp = NULL;
		int size = s1.size();
		dp = new bool**[size];
		for (int i = 0; i < size; ++ i)
		{
			dp[i] = new bool*[size];
			for (int j = 0; j < size; ++ j)
				dp[i][j] = new bool[size+1];
		}
		for (int i = size-1; i >= 0; -- i)
		{
			for (int j = size-1; j >= 0; -- j)
			{
				for (int k = 1; k <= size-max(i, j); ++ k)
				{
					if (s1.substr(i, k) == s2.substr(j, k))
						dp[i][j][k] = true;
					else {
						dp[i][j][k] = false; // 初始化
						for (int p = 1; p < k; ++ p)
						{
							if (dp[i][j][p] && dp[i+p][j+p][k-p] || dp[i][j+k-p][p] && dp[i+p][j][k-p]) {
								dp[i][j][k] = true;
								break;
							}
						}
					}
				}
			}
		}
		return dp[0][0][size];
	}
};