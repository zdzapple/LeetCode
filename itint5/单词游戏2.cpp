bool dfs(const vector<vector<char> > &grid, 
		vector<vector<bool> > &isVisited, 
		const string &pattern, 
		int currentIndex, 
		int row, int col)
{
	isVisited[row][col] = true;
	int n = grid.size();
	int m = grid[0].size(); 
	static int dx[] = {0, 1, 0, -1};
    static int dy[] = {1, 0, -1, 0}; 
	if (currentIndex == pattern.size() - 1) {
		isVisited[row][col] = false;
		return true;
	}
	for (int d = 0; d < 4; d ++) 
	{
		int nx = row + dx[d], ny = col + dy[d];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !isVisited[nx][ny] 
				&& grid[nx][ny] == pattern[currentIndex + 1]) {
			if (dfs(grid, isVisited, pattern, currentIndex + 1, nx, ny)) return true;
		}
	}
	isVisited[row][col] = false;
	return false;
}

bool exists(vector<vector<char> > &grid, vector<string> &patterns) 
{
	if (patterns.empty())
		return true;
	if (grid.empty())	
		return false;
	int chars[256];
	int m = grid.size();
	int n = grid[0].size();
	memset(chars, 0, sizeof(chars));
	int i, j;
	for (i = 0; i < m; ++ i)
	{
		for (j = 0; j < n; ++ j)
		{
			chars[grid[i][j]] ++;
		}
	}
	for (i = 0; i < patterns.size(); ++ i)
	{	
		string pattern = patterns[i];
		int haveFoundchar[256] = {0};
		for (j = 0; j < pattern.size(); ++ j)
		{
			if (chars[pattern[j]] == 0)
				break;
			haveFoundchar[pattern[j]] ++;
			if (haveFoundchar[pattern[j]] > chars[pattern[j]])
				break;
		}
		if (j == pattern.size()) {
			vector<vector<bool> > isVisited(m, vector<bool>(n, false));
			for (int x = 0; x < m; ++ x)
			{
				for (int y = 0; y < n; ++ y)
				{
					if (pattern[0] == grid[x][y]) {
						if (dfs(grid, isVisited, pattern, 0, x, y))
							return true;
					}
				}
			}
		}
		
	}
	return false;
}

/**
struct TrieNode {
    TrieNode *children[26];
    bool end;
    TrieNode() {
        end = false;
        memset(children, 0, sizeof(children));
    }
    void add(string& str, int ind) {
        if (end) return; // 如果pattern p1是p2的前缀，那么p2就没必要搜索了。
        if (ind == str.size()) {
            end = true;
            return;
        }
        if (!children[str[ind] - 'A']) children[str[ind] - 'A'] = new TrieNode();
        children[str[ind] - 'A']->add(str, ind + 1);
    }
};

bool vis[120][120];
bool exists(vector<vector<char> > &board, int x, int y, TrieNode *node) {
    static int dx[] = {0,1,0,-1};
    static int dy[] = {1,0,-1,0};

    if (!node) return false;
    TrieNode *nextNode = node->children[board[x][y] - 'A'];
    if (!nextNode) return false;
    if (nextNode->end) return true;
    vis[x][y] = true;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !vis[nx][ny]) {
            if (exists(board, nx, ny, nextNode)) return true;
        }
    }
    vis[x][y] = false;
    return false;
}
bool exists(vector<vector<char> > &grid, vector<string> &patterns) {
    // build trie tree
    TrieNode root;
    for (int i = 0; i < patterns.size(); i++)
        root.add(patterns[i], 0);

    for (int x = 0; x < grid.size(); x++) {
        for (int y = 0; y < grid[0].size(); y++) {
            if (!root.children[grid[x][y] - 'A']) continue;
            memset(vis, false, sizeof(vis));
            // search from (x,y)
            if (exists(grid, x, y, &root)) return true;
        }
    }
    return false;
}
**/