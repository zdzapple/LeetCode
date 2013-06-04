class Solution 
{
public:	
	// dfs
	void dfs(vector<int> &num, vector<bool> &visited, int curLevel, int maxLevel, vector<vector<int> > &result, vector<int> &solution)
	{
		if (curLevel == maxLevel) {
			result.push_back(solution);
			return;
		}
		for (int i = 0; i < num.size(); ++ i)
		{
			if (!visited[i]) {
				if (i > 0 && num[i] == num[i-1] && !visited[i-1])
					continue;
				visited[i] = true;
				solution.push_back(num[i]);
				dfs(num, visited, curLevel + 1, maxLevel, result, solution);
				visited[i] = false;
				solution.pop_back();
			}
		}
	}
	
	vector<vector<int> > permuteUnique(vector<int> &num) 
	{
        vector<vector<int> > result;
		vector<int> solution;
		vector<bool> visited(num.size(), false);
		if (num.size() == 0)
			return result;
		sort(num.begin(), num.end());
		dfs(num, visited, 0, num.size(), result, solution);		
        return result;
    }
};