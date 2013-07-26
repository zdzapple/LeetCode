class Solution 
{
public:
	void dfs(int level,  vector<int> &location, int &result, const int &n)
	{
		if (level == n) {
			result ++;
			return;
		}
		for (int i = 0; i < n; ++ i)
		{
			if (canPut(level, i, location)) {
				location.push_back(i);
				dfs(level+1, location, result, n);
				location.pop_back();
			}
		}
	}

	// whether queen k can put in the column
	bool canPut(const int k, const int col, const vector<int> &location)
	{
		if (k == 0)
			return true;
		if (abs(location[k-1] - col) == 1)
			return false;
		for (int i = 0; i <= k-1; ++ i)
		{
			if (location[i] == col || abs(k - i) == abs(location[i] - col))
				return false;
		}
		return true;
	}
	
    int totalNQueens(int n) 
	{
		vector<int> location;
		if (n <= 0)
			return 0;
		int result = 0;
		dfs(0, location, result, n);
		return result;
        
    }
};