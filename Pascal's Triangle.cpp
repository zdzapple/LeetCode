class Solution 
{
public:
    vector<vector<int> > generate(int numRows) 
	{
        vector<vector<int> > result;
		if (numRows <= 0)
			return result;
		vector<int> row(1, 1);
		result.push_back(row);
		for (int i = 2; i <= numRows; ++ i)
		{
			vector<int> tmp(row);
			row.clear();
			row.push_back(1);
			for (int j = 1; j < i - 1; ++ j)
			{
				row.push_back(tmp[j-1] + tmp[j]);
			}
			row.push_back(1);
			result.push_back(row);
		}
		return result;
        
    }
};