class Solution 
{
public:
	bool isValid(vector<char> &chain)
	{
		vector<int> dup(10, 0);//hash for 1 to 9
		// memset(dup, 0, sizeof(dup) / sizeof(int)); is wrong.
		// memset(dup, 0, sizeof(dup)); is correct
		// or memset(dup, 0, sizeof(int) * 10);
		for (int i = 1; i <= chain.size(); ++ i)
		{
			if (chain[i-1] != '.')
				if (dup[chain[i-1] - '0'] != 0)
					return false;
				else
					dup[chain[i-1] - '0'] = 1;
		}
		return true;
	}
	
	bool isValidSubBox(vector<vector<char> > &subBox)
	{
		vector<int> dup(10, 0);//hash for 1 to 9
		// memset(dup, 0, sizeof(dup) / sizeof(int));
		for (int i = 0; i < subBox.size(); ++ i)
		{
			for (int j = 0; j < subBox[0].size(); ++ j)
			{
				if (subBox[i][j] != '.')
					if (dup[subBox[i][j] - '0'] != 0)
						return false;
					else
						dup[subBox[i][j] - '0'] = 1;
			}
			
		}
		return true;
	}

    bool isValidSudoku(vector<vector<char> > &board) 
	{
        int m = board.size();
		if (board.empty())
			return false;
		int n = board[0].size();
		if (m != n || m != 9)
			return false;
		vector<char> chain;
		for (int row = 0; row < m; ++ row)
		{
			chain = board[row];
			if (!isValid(chain))
				return false;
		}
		for (int col = 0; col < n; ++ col)
		{
			chain.clear();
			for (int row = 0; row < m; ++ row)
				chain.push_back(board[row][col]);
			if (!isValid(chain))
				return false;
		}
		// check the sub-boxes
        for (int row = 0; row < 9; row += 3)
		{
			for (int col = 0; col < 9; col += 3)
			{
				vector<vector<char> > subBoxes(3, vector<char>(3, ' '));;
				for (int i = 0; i < 3; ++ i)
				{
					for (int j = 0; j < 3; ++ j)
					{
						subBoxes[i][j] = board[row + i][col + j];
					}
				}
				if (!isValidSubBox(subBoxes))
					return false;
			}
		}
		return true;
    }
};

/**

public class Solution {
    public boolean isValidSudoku(char[][] board) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int [][] table=new int[27][9];
        int [][] squareIndex = new int [][] {{0,1,2}, {3,4,5}, {6,7,8}};
        for(int i=0; i<9; i++){ // rows
            for(int j=0; j<9; j++){ // cols
                if(board[i][j]=='.')
                    continue;
                if(!Character.isDigit(board[i][j]))
                    return false;
                int val = Character.getNumericValue(board[i][j]);
                // Rows
                if(table[i][val-1]!=0)
                    return false;
                table[i][val-1]=1;
                // Columns
                if(table[j+9][val-1]!=0)
                    return false;
                table[j+9][val-1]=1;
                // Squares
                int sNdx = squareIndex[i/3][j/3];
                if(table[sNdx+18][val-1]!=0)
                    return false;
                table[sNdx+18][val-1]=1;
            }
        }
        return true;
    }
}
**/