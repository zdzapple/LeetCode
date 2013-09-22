bool dfs(const vector<vector<char> > &grid, 
		vector<vector<bool> > &isVisited, 
		const string &pattern, 
		int currentIndex, 
		int row, int col)
{
	isVisited[row][col] = true;
	int n = grid.size();
	int m = grid[0].size(); 
	if (currentIndex == pattern.size() - 1) {
		isVisited[row][col] = false;
		return true;
	}
	bool success = false;
	if (row < n-1 && grid[row+1][col] == pattern[currentIndex + 1] && !isVisited[row+1][col]) {
		if (dfs(grid, isVisited, pattern, currentIndex + 1, row + 1, col)) {
			success = true;
		}
	}
	if (!success && row > 0 && grid[row-1][col] == pattern[currentIndex + 1] && !isVisited[row-1][col]) {
		if (dfs(grid, isVisited, pattern, currentIndex + 1, row - 1, col))
			success = true;
	}
	if (!success && col < m-1 && grid[row][col+1] == pattern[currentIndex + 1] && !isVisited[row][col+1]) {
		if (dfs(grid, isVisited, pattern, currentIndex + 1, row, col + 1))
			success = true;
	}
	if (!success && col > 0 && grid[row][col-1] == pattern[currentIndex + 1] && !isVisited[row][col-1]) {
		if (dfs(grid, isVisited, pattern, currentIndex + 1, row, col - 1))
			success = true;
	}
	
	isVisited[row][col] = false;
	return success;
}

bool exists(vector<vector<char> > &grid, string pattern) 
{
	if (grid.empty())
		return false;
	if (pattern.empty())
		return true;
	int n = grid.size();
	int m = grid[0].size();
	
	vector<vector<bool> > isVisited(n, vector<bool>(m, false));
	for (int i = 0; i < n; ++ i)
	{
		for (int j = 0; j < m; ++ j)
		{
			if (pattern[0] == grid[i][j]) {
				if (dfs(grid, isVisited, pattern, 0, i, j))
					return true;
			}
		}
	}
	return false;
}