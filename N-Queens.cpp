class Solution 
{
public:
	// location[i] indicates the column that the ith queen at.
	void dfs(int level,  vector<int> &location, vector<string> &current, vector<vector<string> > &result, const int &n)
	{
		if (level == n) {
			result.push_back(current);
			return;
		}
		for (int i = 0; i < n; ++ i)
		{
			if (canPut(level, i, location)) {
				location.push_back(i);
				string str(n, '.');
				str[i] = 'Q';
				current.push_back(str);
				dfs(level+1, location, current, result, n);
				current.pop_back();
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
	
    vector<vector<string> > solveNQueens(int n) 
	{
        vector<int> location;
		vector<vector<string> > puzzle;
		vector<string> str;
		if (n <= 0)
			return puzzle;
		dfs(0, location, str, puzzle, n);
		return puzzle;
        
    }
};