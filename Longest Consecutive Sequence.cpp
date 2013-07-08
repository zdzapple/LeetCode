class Solution 
{
public:
    int longestConsecutive(vector<int> &num) 
	{
        map<int, int> m;
		int n = num.size();
		int i = 0;
		vector<bool> visited(n, false);
		for (i = 0; i < n; ++ i)
		{
			m[num[i]] = i;
		}
		int solution = 0;
		int result = 0;
		for (i = 0; i < n; ++ i)
		{
			if (visited[i])
				continue;
			int number = num[i] + 1;
			map<int, int>::iterator it;
			solution = 1;
			while (m.find(number) != m.end())
			{
				solution ++;
				visited[m[number]] = true;
				number ++;
			}
			number = num[i] - 1;
			while (m.find(number) != m.end())
			{
				solution ++;
				visited[m[number]] = true;
				number --;
			}
			if (result < solution)
				result = solution;
		}
		return result;
    }
};