// 从每一个元素开始dfs，效率不高，会超内存
// 转换思路，从边上的元素开始dfs，访问的元素都不用flip
class Solution 
{
public:
    void dfs(int m, int n, vector<vector<char> > &board)
	{
		if (m >= board.size() || n >= board[0].size()) return;  
		if (board[m][n] == 'O') {
			board[m][n] = 'n';
			if (m > 0) {			
				dfs(m-1, n, board);			
			}
			if (m < board.size() - 1) {
				dfs(m+1, n, board);	
			}
			if (n > 0) {			
				dfs(m, n-1, board);
			}
			
			if (n < board[0].size() - 1) {
				dfs(m, n+1, board);
			}
		} 
	}
	
	void solve(vector<vector<char>> &board)
	{
		if (board.empty())
			return;
        int row = board.size();
		int col = board[0].size();
		int i, j;
		for (i = 0; i < col; ++ i)
		{
			//if (board[0][i] == 'O') {
				dfs(0, i, board);
			//}
		}
		for (i = 0; i < col; ++ i)
		{
			//if (board[row-1][i] == 'O') {
				dfs(row-1, i, board);
			//}
		} 
		for (i = 1; i < row - 1; ++ i)
		{
			//if (board[i][0] == 'O') {
				dfs(i, 0, board);
			//}
		}
		for (i = 1; i < row -1; ++ i)
		{
			//if (board[i][col-1] == 'O') {
				dfs(i, col-1, board);
			//}
		} 
		for(i = 0; i < row; i ++){  
            for(j = 0; j < col; j ++){  
				if (board[i][j] == 'O')
					board[i][j] = 'X';  
               
            }  
        }  
		for(i = 0; i < row; i ++){  
            for(j = 0; j < col; j ++){  
				 if (board[i][j] == 'n')
					board[i][j] = 'O';
               
            }  
        }  
		  
    }
};