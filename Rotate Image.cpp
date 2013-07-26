class Solution 
{
public:
	void rotateAround(vector<vector<int> > &matrix, int row, int col, int n)
	{
		for (int i = 0; i < n-1; ++ i)
		{
			int temp = matrix[row][col+i];
			matrix[row][col+i] = matrix[row+n-1-i][col];
			matrix[row+n-1-i][col] = matrix[row+n-1][col+n-1-i];
			matrix[row+n-1][col+n-1-i] = matrix[row+i][col+n-1];
			matrix[row+i][col+n-1] = temp;
		}
	}
	
    void rotate(vector<vector<int> > &matrix) 
	{
        if (matrix.empty())
			return;
		int n = matrix.size();
		for (int i = 0; i < n / 2; i ++)
		{
			rotateAround(matrix, i, i, n - 2*i);
		}
        
    }
};