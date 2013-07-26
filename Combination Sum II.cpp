class Solution 
{
public:
	void dfs(int level, int &sum, int &target, vector<int> &candidates, vector<int> &solution, vector<vector<int> > &result)
	{
		if (sum == target) {
			result.push_back(solution);
			return;
		}
		if (sum > target)
			return;
		for (int i = level; i < candidates.size(); ++ i)
		{
			sum += candidates[i];
			solution.push_back(candidates[i]);
			dfs(i + 1, sum, target, candidates, solution, result);
			solution.pop_back();
			sum -= candidates[i];
			// skip the duplicate numbers
			while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1])
				++ i;
		}
	}

    vector<vector<int> > combinationSum2(vector<int> &num, int target)
	{
        vector<vector<int> > result;
		if (num.empty() || target < 0)
			return result;
		sort(num.begin(), num.end());
		vector<int> solution;
		int sum = 0;
		dfs(0, sum, target, num, solution, result);
		return result;
        
    }
};

/**
class Solution 
{
public:
	void dfs(int level, int &sum, int &target, vector<int> &candidates, vector<int> &solution, set<vector<int> > &result)
	{
		if (sum == target) {
			result.insert(solution);
			return;
		}
		if (sum > target || level == candidates.size())
			return;
		sum += candidates[level];
		solution.push_back(candidates[level]);
		dfs(level + 1, sum, target, candidates, solution, result);
		solution.pop_back();
		sum -= candidates[i];
		dfs(level + 1, sum, target, candidates, solution, result);
		
	}

    vector<vector<int> > combinationSum2(vector<int> &num, int target)
	{
        set<vector<int> > result;
		vector<vector<int> > re;
		if (num.empty() || target < 0)
			return re;
		sort(num.begin(), num.end());
		vector<int> solution;
		int sum = 0;
		dfs(0, sum, target, num, solution, result);
		
		for (std::set<vector<int> >::iterator it = result.begin(); it != result.end(); ++ it)
			re.push_back(*it);
		return re;
        
    }
};

**/