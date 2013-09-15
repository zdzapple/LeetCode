const int ROW_NUM = 9;
bool isValid(vector<int> arr)
{
	int numberCount[10] = {0};
	for (int i = 0; i < ROW_NUM; ++ i)
	{
		if (arr[i] > 9 || arr[i] < 1 || numberCount[arr[i]] >= 1)
			return false;
		numberCount[arr[i]] = 1;
	}
	return true;
}

int isValidSudoku(int arr[]) 
{
	if (strlen(arr) != ROW_NUM * ROW_NUM)
		return 0;
	// check Row
	for (int i = 0; i < ROW_NUM; ++ i)
	{
		vector<int> row(arr + i * ROW_NUM, arr + (i+1) * ROW_NUM);
		if (!isValid(row))
			return 0;
	}
	// check col
	for (int i = 0; i < ROW_NUM; ++ i)
	{
		vector<int> col;
		for (int j = 0; j < ROW_NUM; ++ j)
		{
			col.push_back(arr[i + j * ROW_NUM]);
		}
		if (!isValid(col))
			return 0;
	}
	// check grid
	for (int j = 0; j < ROW_NUM; j += 3)
	{
		vector<int> grid;
		for (int j = 0; j < ROW_NUM; j += 3)
		{
			for (int k = 0; k < 3; ++ k)
			{
				grid.insert(grid.end(), arr + (i * 3+k) * ROW_NUM + j, arr+(i * 3+k)*ROW_NUM + j + 3);
			}
			if (!isValid(grid))
				return 0;
		}
	}
	return 1;
}