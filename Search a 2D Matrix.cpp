class Solution 
{
public:
	int binarySearch(vector<int> &num, int target)
	{
		if (num.empty())
			return -1;
		int begin = 0;
		int end = num.size() - 1;
		if (target < num[0] || target > num[end])
			return -1;
		while (begin <= end)
		{
			int mid = begin + (end - begin) / 2;
			if (num[mid] == target)
				return mid;
			if (num[mid] > target)
				end = mid - 1;
			else
				begin = mid + 1;
		}
		return -1;
	}
	
    bool searchMatrix(vector<vector<int> > &matrix, int target) 
	{
        if (matrix.empty())
			return false;
		int row = matrix.size();
		int col = matrix[0].size();
		if (target < matrix[0][0] || target > matrix[row-1][col-1])
			return false;
		// search the target in the range of [beginRow, endRow]
		int beginRow = 0;
		int endRow = row - 1;
		while (beginRow <= endRow)
		{
			int mid = beginRow + (endRow - beginRow) / 2;
			if (matrix[mid][0] == target)
				return true;
			if (matrix[mid][0] > target)
				endRow = mid - 1;
			else {
				if (matrix[mid][col-1] >= target) {
					beginRow = mid;
					break;
				} else 
					beginRow = mid + 1;
			}
		}
        if (binarySearch(matrix[beginRow], target) != -1)
			return true;
		return false;
    }
};