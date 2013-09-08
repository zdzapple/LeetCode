// 凡是求最优解的，一般都是走DP的路线。
class Solution 
{
public:
	 bool isPalindrome1(string &s, int start, int end)  
    {  
		while (start< end)  
		{  
			if(s[start] != s[end])  
				return false;  
			start++; end--;  
		}  
      return true;  
   }  
	// 搜索+剪枝 Time Limit Exceeded
	void dfs(string& s, int start, int depth, int& min)
	{
		if (s.size() == start) {
			if (min > depth - 1)
				min = depth - 1;
			return;
		}
		for (int i = s.size() - 1; i >= start; -- i)
		{
			if (isPalindrome1(s, start, i)) {
				dfs(s, i + 1, depth + 1, min);
			}
		}
	}
	
    int minCutDFS(string s) 
	{
        if (s.empty() || s.size() <= 1)
			return 0;
		int min = INT_MAX;
		dfs(s, 0, 0, min);
        return min;
    }
	
	// DP version
	// D[i, n] = min(D[i,j] + D[j+1, n]) + 1;
	// 改成1维的：i向右扫描，每次找到一个回文[i,j]，就计算一次
	// D[i] 表示区间[i,n]之间最小的cut数
	// D[i] = min(D[j+1] + 1)
	// 判断[i,j]是否为回文，P[i][j] = true if str[i]=str[j] && P[i+1][j-1]=true
	int minCut(string s) 
	{
        if (s.empty() || s.size() <= 1)
			return 0;
		int len = s.size();
		int D[len + 1];
		bool isPalindrome[len][len];
		int i, j;
		for (i = 0; i < len; ++ i)
			for (j = 0; j < len; ++ j)
				isPalindrome[i][j] = false;
		// 初始化
		for (i = 0; i <= len; i ++)   
			D[i] = len - i - 1;
		for (i = len - 1; i >= 0; -- i)
		{
			for (j = i; j <= len - 1; ++ j)
			{
				if (s[i] == s[j] && (j - i <= 1 || isPalindrome[i+1][j-1] == true)) {
					isPalindrome[i][j] = true;
					D[i] = min(D[i], D[j+1] + 1); // note: j + 1
				}
			}
		}
		return D[0];
    }
};