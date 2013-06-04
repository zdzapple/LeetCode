class Solution
 {
public:
	void dfs(vector<vector<int> > &result, int maxLevel, int level, vector<int> &current, int k)
	{
		if (current.size() == k) {
			result.push_back(current);
			return;
		}
		if (level - 1 == maxLevel) {
			return;
		}
		if (current.size() < k) {
			current.push_back(level);
			dfs(result, maxLevel, level + 1, current, k);
			current.pop_back();
			dfs(result, maxLevel, level + 1, current, k);
		}
	}
	
	void dfs1(vector<vector<int> > &result, int n, int level, vector<int> &solution, int k)
	{
		if(solution.size() == k)  
		{  
			result.push_back(solution);  
			return;  
		}  
		for(int i = level; i <= n; i ++)  
		{  
			solution.push_back(i);  
			dfs1(result, n, i + 1, solution, k);  
			solution.pop_back();  
		}  
	}
	
    vector<vector<int> > combine(int n, int k) 
	{       
        vector<vector<int> > result;
		if (n < 1 || k > n)
			return result;
		if (n == k) {
			vector<int> v;
			for (int i = 1; i <= n; ++ i)
				v.push_back(i);
			result.push_back(v);
			return result;
		}
		vector<int> cur;
		//dfs(result, n, 1, cur, k);
		dfs1(result, n, 1, cur, k);
		return result;
		
    }
};