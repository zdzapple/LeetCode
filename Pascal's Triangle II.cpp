class Solution 
{
public:
	vector<int> getRow(int rowIndex)
	{
		// take [1 3 3 1] and [1 4 6 4 1] for example, the element in the last row is only relative to the element in the previous row and the one before the element in the privious row. So we can generate the last row from the previous row in backward order without extra vectors. 
		vector<int> row;
		if (rowIndex < 0)
			return row;
		for (int i = 0; i <= rowIndex; ++ i)
		{
			row.push_back(1);
			for (int j = i - 1; j > 0; -- j)
			{
				row[j] = row[j] + row[j-1];
			}
		}
		return row;
	}

    vector<int> getRow1(int rowIndex) 
	{
		vector<int> row;
		if (rowIndex < 0)
			return row;
		row.push_back(1);
		for (int i = 1; i <= rowIndex; ++ i)
		{
			vector<int> tmp(row);
			row.clear();
			row.push_back(1);
			for (int j = 1; j < i; ++ j)
			{
				row.push_back(tmp[j-1] + tmp[j]);
			}
			row.push_back(1);
		}
		return row;        
    }
};