class Solution 
{
public:
	bool dfs(vector<vector<char> > &board, string word, int level, int row, int col, vector<vector<bool> > &visited)
	{
		if (level == word.size() - 1) // 不是level == word.size(). special case: board:"a" word:"a"
			return true;
		int sizeR = board.size();
		int sizeC = board[0].size();
		if (col >= 1 && !visited[row][col-1] && board[row][col-1] == word[level+1]) {
			visited[row][col-1] = true;
			if (dfs(board, word, level + 1, row, col-1, visited))
				return true;
			visited[row][col-1] = false;
		}
		if (col <= sizeC - 2 && !visited[row][col+1] && board[row][col+1] == word[level+1]) {
			visited[row][col+1] = true;
			if (dfs(board, word, level + 1, row, col+1, visited))
				return true;
			visited[row][col+1] = false;
		}
		if (row >= 1 && !visited[row-1][col] && board[row-1][col] == word[level+1]) {
			visited[row-1][col] = true;
			if (dfs(board, word, level + 1, row-1, col, visited))
				return true;
			visited[row-1][col] = false;
		}
		if (row <= sizeR - 2 && !visited[row+1][col] && board[row+1][col] == word[level+1]) {
			visited[row+1][col] = true;
			if (dfs(board, word, level + 1, row+1, col, visited))
				return true;
			visited[row+1][col] = false;
		}
		return false;	
	}
	
    bool exist(vector<vector<char> > &board, string word) 
	{
        if (board.empty())
			return false;
		if (word.empty())
			return true;
		
		for (int i = 0; i < board.size(); ++ i)
		{
			for (int j = 0; j < board[i].size(); ++ j)
			{
				if (word[0] == board[i][j]) {
					vector<vector<bool> > visited;
					for (int k = 0; k < board.size(); ++ k)
					{
						vector<bool> v(board[k].size(), false);
						visited.push_back(v);
					}
					visited[i][j] = true;
					if (dfs(board, word, 0, i, j, visited))
						return true;
				}
			}
		}
		return false;
    }
};