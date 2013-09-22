int totalPath(vector<vector<bool> > &blocked) 
{
	if (blocked.empty())
		return 1;
	int m = blocked.size();
	int n = blocked[0].size();
	vector<vector<int> > steps(m, vector<int>(n, 0));
	int i, j;
	for (i = 0; i < n; ++ i) {
		if (!blocked[0][i])
			steps[0][i] = 1;
		else
			break;
	}
	for (i = 0; i < m; ++ i) {
		if (!blocked[i][0])
			steps[i][0] = 1;
		else
			break;
	}
	for (i = 1; i < m; ++ i)
	{
		for (j = 1; j < n; ++ j)
		{
			if (!blocked[i][j] && !(blocked[i-1][j] && blocked[i][j-1])) {
				if (steps[i-1][j] != 0 ||  steps[i][j-1] != 0)
					steps[i][j] = steps[i-1][j] + steps[i][j-1];
			}
		}
	}
	return steps[m-1][n-1];
}