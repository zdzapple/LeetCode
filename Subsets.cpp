class Solution 
{
public:
	void dfs(vector<vector<int> > &result, vector<int> &S, int level, vector<int> &solution, int k)
	{
		if (solution.size() == k)  
		{  
			result.push_back(solution);  
			return;  
		}  
		for (int i = level; i <= S.size(); i ++)  
		{  
			solution.push_back(S[i - 1]);  
			dfs(result, S, i + 1, solution, k);  
			solution.pop_back();  
		}  
	}
	
    vector<vector<int> > subsets1(vector<int> &S) 
	{
		vector<vector<int> > result;
		vector<int> subset;
		result.push_back(subset);
        if (S.empty())
			return result;
		sort(S.begin(), S.end());
		
		vector<int> cur;
		for (int i = 1; i <= S.size(); ++ i) {
			cur.clear();
			dfs(result, S, 1, cur, i);
		}
		return result;
        
    }
	
	/**
	(a,b,c)
	(1,1,1)->(a,b,c)
	(1,1,0)->(a,b   )
	(1,0,1)->(a,   c)
	(1,0,0)->(a      )
	(0,1,1)->(   b,c)
	(0,1,0)->(   b   )
	(0,0,1)->(      c)
	(0,0,0)->@	(@表示空集)
	**/
	vector<vector<int> > subsets(vector<int> &S) 
	{
		vector<vector<int> > result;
        if (S.empty())
			return result;
		sort(S.begin(), S.end());
		
		vector<bool> bits(S.size(), false);
		int i;
		int n = S.size();
		while (true)
		{
			vector<int> subset;
			for (i = 0; i < n; ++ i)
			{
				if (bits[i])
					subset.push_back(S[i]);
			}
			result.push_back(subset);
			
			bool overflow = true;
			for (i = 0; overflow && i < n; ++ i)
			{
				overflow = overflow && bits[i];
				bits[i] = !bits[i];
			}
			if (overflow) break;			
		}
		return result;
        
    }
};

/**
class Solution {
public:
    vector< vector<int> > subsets(vector<int>& numbers) {
        vector< vector<int> > result;
        sort(numbers.begin(), numbers.end());
        // Loop from 0 to 2^n - 1
        for (int x = 0; x < (1 << numbers.size()); ++x) {
            vector<int> sln;
            for (int i = 0; i < numbers.size(); ++i)
                // If the i-th least significant bit is 1, then choose
                // the i-th integer
                if (x & (1 << i))
                    sln.push_back(numbers[i]);
            result.push_back(sln);
        }
        return result;
    }
};

**/