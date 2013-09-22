void dfs(vector<string> &parentheses, const int &n, int currentLeft, int currentRight, string &currentStr)
{
	if (currentLeft == n) {
		string rightParenteses(n - currentRight, ')');
		parentheses.push_back(currentStr + rightParenteses);
		return;
	}
	currentStr += '(';
	dfs(parentheses, n, currentLeft + 1, currentRight, currentStr);
	currentStr.erase(currentStr.size() - 1);
	if (currentRight < currentLeft) {
		currentStr += ')';
		dfs(parentheses, n, currentLeft, currentRight + 1, currentStr);
		currentStr.erase(currentStr.size() - 1);
	}
}

vector<string> generate(int n)
{
	vector<string> parentheses;
	if (n <= 0)
		return parentheses;
	string str;
	dfs(parentheses, n, 0, 0, str);
	return parentheses;
}