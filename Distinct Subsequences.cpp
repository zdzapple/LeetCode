class Solution 
{
public:
    // large set : Time Limit Exceeded
	void subsequences(string &S, string &T, int &numDistinct)
	{
		if (T.size() == 0) {
			numDistinct ++;
			return;
		}
		if (S.empty())
			return;
		
		for (int i = 0; i < S.size(); ++ i)
		{
			if (S[i] == T[0]) {
				string sub = S.substr(i+1);
				string tsub = T.substr(1);
				subsequences(sub, tsub, numDistinct);
			}
		}
		
	}
	/**
	* let f(i, j) to be the number of distinct subsequences of T(j:) in S(i:). 
	If we can match S[i] and  T[j], namely S[i] == T[j], then f(i, j) = f(i+1, j+1);
	If we do not want use it in our matching, then f(i, j) = f(i+1, j)
	thus, f(i, j) = f(i+1, j) + (S[i] == T[j]) * f(i+1, j+1)
	**/
    int numDistinct1(string S, string T) 
	{
        /*int result = 0;
		if (S.empty() || T.empty())
			return 0;
		subsequences(S, T, result);
		return result;*/
        if (S.size() < T.size())
			return 0;  
		vector<vector<int> > f(S.size() + 1, vector<int>(T.size() + 1));
		f[S.size()][T.size()] = 1;
		for (int i = 0; i < T.size(); ++ i)
			f[S.size()][i] = 0;
		for (int i = 0; i < S.size(); ++ i)
			f[i][T.size()] = 1;
		for (int i = S.size() - 1; i >= 0; -- i)// to calculate f[i][j], we need f[i+1][j] and f[i+1][j+1]
		{
			for (int j = 0; j < T.size(); ++ j) 
			{
				f[i][j] = f[i+1][j] + (S[i] == T[j]) * f[i+1][j+1];
			}
		}
		return f[0][0];
    }
	
	/**
	* we can use only 1-dim vector
	**/
    int numDistinct(string S, string T) 
	{
        if (S.size() < T.size())
			return 0;  
		vector<int> f(T.size() + 1);
		f[T.size()] = 1;
		for (int i = S.size() - 1; i >= 0; -- i)// to calculate f[i][j], we need f[i+1][j] and f[i+1][j+1]
		{
			for (int j = 0; j < T.size(); ++ j) 
			{
				f[j] = f[j] + (S[i] == T[j]) * f[j+1];
			}
		}
		return f[0];
    }
};