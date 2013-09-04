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
			dfs(i, sum, target, candidates, solution, result);
			solution.pop_back();
			sum -= candidates[i];
		}
	}

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) 
	{
        vector<vector<int> > result;
		if (candidates.empty() || target < 0)
			return result;
		sort(candidates.begin(), candidates.end());
		vector<int> solution;
		int sum = 0;
		dfs(0, sum, target, candidates, solution, result);
		return result;
        
    }
};


/**
DP solution:

sum[i] = sum{sum[j], target - j}

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) 
	{
        
        vector< vector <vector<int> > > sum(target+1);
        for (int i = 1; i <= target; ++i)
        {
            int nSize = candidates.size();
            for (int j = 0; j < nSize; ++j)
            {
                if (i < candidates[j])
                    continue;
                else if (i == candidates[j])
                {
                    sum[i].push_back(vector<int>());
                    sum[i].back().push_back(candidates[j]);
                    continue;
                }
                else
                {
                    int tmp = i - candidates[j];
                    for (int k = 0; k < sum[tmp].size(); ++k)
                    {
                        if (sum[tmp][k].back() <= candidates[j])
                        {
                            sum[i].push_back(vector<int>(sum[tmp][k]));
                            sum[i].back().push_back(candidates[j]);
                        }
                    }
                }
            }
        }
        return sum[target];
    }
};
**/