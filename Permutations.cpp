class Solution 
{
public:
	void swap(vector<int> &num, int i, int j)
	{
		int temp = num[i];
		num[i] = num[j];
		num[j] = temp;
	}
	
	void perm(vector<int> &num, int start, int end, vector<vector<int> > &result)
	{
		if (start == end) {
			result.push_back(num);
			return;
		}
		for (int i = start; i <= end; ++ i)
		{
			swap(num, start, i);
			perm(num, start + 1, end, result);
			swap(num, start, i);
		}
	}
	
    vector<vector<int> > permute1(vector<int> &num) 
	{
        vector<vector<int> > result;
		perm(num, 0, num.size() - 1, result);		
        return result;
    }
	
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
				visited[i] = true;
				solution.push_back(num[i]);
				dfs(num, visited, curLevel + 1, maxLevel, result, solution);
				visited[i] = false;
				solution.pop_back();
			}
		}
	}
	
	vector<vector<int> > permute(vector<int> &num) 
	{
        vector<vector<int> > result;
		vector<int> solution;
		vector<bool> visited(num.size(), false);
		if (num.size() == 0)
			return result;
		dfs(num, visited, 0, num.size(), result, solution);		
        return result;
    }
};