/*矩形的定义:
struct Rect {
    int x1,y1,x2,y2;
}*/
#include <climits>
int maxConsSum(const vector<int> &arr, int w, int row)
{
	int n = arr.size();

	int curSum = 0;
	for (int j = 0; j < w; ++ j)
    {
		curSum += arr[j];
    }

    int maxSum = curSum;
	for (int i = w; i <= n - 1; ++ i)
	{
		curSum = curSum - arr[i-w];
		curSum += arr[i];
		maxSum = max(curSum, maxSum);
	}
	return maxSum;
}

int minOverlapping(vector<Rect> &rects, int W, int H, int w, int h)
{
	if (rects.empty())
		return 0;
	vector<vector<int> > matrix(H, vector<int>(W, 0));
	for (int i = 0; i < rects.size(); ++ i)
	{
		for (int row = rects[i].x1; row < rects[i].x2; ++ row)
		{
			for (int col = rects[i].y1; col < rects[i].y2; ++ col)
			{
				matrix[row][col] = -1;
			}
		}
	}
	int result = INT_MIN;
	vector<int> subMatrix(matrix[0].size(), 0);
	for (int row = 0; row < H - h + 1; ++ row)
	{
		if (row == 0)
			for (int j = row; j < row + h; ++ j)
			{
				for (int k = 0; k < matrix[0].size(); ++ k)
				{
					subMatrix[k] += matrix[j][k];
				}
			}
		else {
			for (int k = 0; k < matrix[0].size(); ++ k)
			{
				subMatrix[k] -= matrix[row-1][k];
				subMatrix[k] += matrix[row+h-1][k];
			}
		}

		result = max(result, maxConsSum(subMatrix, w, row));
	}
	return 0 - result;
}