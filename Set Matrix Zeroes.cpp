#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int> > &matrix, int r, int c)
	{
	    vector<int> temp = matrix[r];
	    int row = matrix.size();
		int col = matrix[0].size();
		for (int i = 0; i < row; ++ i)
			matrix[i][c] = 0;
		for (int i = 0; i < col; ++ i)
			matrix[r][i] = 0;
	}

	// O(m + n) space version
    void setZeroes1(vector<vector<int> > &matrix)
	{
		if (matrix.size() == 0)
			return;
		int row = matrix.size();
		int col = matrix[0].size();

		int i, j;
		bool *isZero = new bool[row + col];
		for (i = 0; i < row + col; ++ i)
			isZero[i] = false;
		for (i = 0; i < row; ++ i)
		{
		    // cout << i << ": ";
			//if (!isZero[i])
			{
				for (j = 0; j < col; ++ j)
				{   // cout << matrix[i][j] << " ";
 					if (matrix[i][j] == 0/* && !isZero[row + j] ERROR!!!!!*/)
					{
						// set its entire row and col to 0
						// setZeroes(matrix, i, j); // ERROR!~~~ do not change the matrix now!!
						isZero[i] = true;
						isZero[row + j] = true;
						// break;
					}
				}
				// cout << endl;
			}

		}

		for (i = 0; i < row; ++ i)
        {
            if (isZero[i]) {
                for (j = 0; j < col; ++ j)
                    matrix[i][j] = 0;
            }
        }
        for (i = 0; i < col; ++ i)
        {
            if (isZero[row + i]) {
                for (j = 0; j < row; ++ j)
                    matrix[j][i] = 0;
            }
        }
	}

	// constant space version
	// 常数空间的话，第一可以考虑是不是固定数量的几个变量能搞定；否则可以考虑是不是问题本身已经提供了足够的空间
	void setZeroes(vector<vector<int> > &matrix)
	{
		if (matrix.size() == 0)
			return;
		int row = matrix.size();
		int col = matrix[0].size();

		int i, j;
		bool isFirstRowZero = false;
		bool isFirstColZero = false;
		// if the first row and first column should be set to 0
		for (i = 0; i < col; ++ i)
			if (matrix[0][i] == 0) {
				isFirstRowZero = true;
				break;
			}
		for (i = 0; i < row; ++ i)
			if (matrix[i][0] == 0) {
				isFirstColZero = true;
				break;
			}

		// search 0 in other positions to sign the first row & column
		for (i = 1; i < row; ++ i)
		{
			for (j = 1; j < col; ++ j)
			{
				if (matrix[i][j] == 0)
				{
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}

		// set 0 in the other positions according to the first row & col.
		for (i = 1; i < row; ++ i)
			for (j = 1; j < col; ++ j)
			{
				if (matrix[0][j] == 0 || matrix[i][0] == 0)
					matrix[i][j] = 0;
			}

		// set 0s for the first row & first column
		if (isFirstRowZero)
			for (i = 0; i < col; ++ i)
				matrix[0][i] = 0;
		if (isFirstColZero)
			for (j = 0; j < row; ++ j)
				matrix[j][0] = 0;

	}


};

int main()
{
    vector<vector<int> > matrix;

    int a[4] = {0,0,0,5};
    vector<int> col(a, a + sizeof(a)  / sizeof(int));
    matrix.push_back(col);
    int a1[4] = {4,3,1,4};
    vector<int> col1(a1, a1 + sizeof(a)  / sizeof(int));
    matrix.push_back(col1);
 int a2[4] = {0,1,1,4};
    vector<int> col2(a2, a2 + sizeof(a)  / sizeof(int));
    matrix.push_back(col2);
     int a3[4] = {1,2,1,3};
    vector<int> col3(a3, a3 + sizeof(a)  / sizeof(int));
    matrix.push_back(col3);
     int a4[4] = {0,0,1,1};
    vector<int> col4(a4, a4 + sizeof(a)  / sizeof(int));
    matrix.push_back(col4);
      for (int i = 0; i < matrix.size(); ++ i)
    {
        vector<int> temp = matrix[i];
        for (int j = 0; j < temp.size();  ++ j)
            //cout << temp[j] << " ";
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    Solution s;
    s.setZeroes(matrix);
    for (int i = 0; i < matrix.size(); ++ i)
    {
        vector<int> temp = matrix[i];
        for (int j = 0; j < temp.size();  ++ j)
            //cout << temp[j] << " ";
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}

