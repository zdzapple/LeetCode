class Solution 
{
public:
	void dfs(vector<string> &result, int level, int left, int right, int n, string s)
	{
		if (left == n) {
			s.append(n-right, ')');
			result.push_back(s);
			return;
		}
		//if (level == 2*n) {
		//	result.push_back(s);
		//	return;
		//}
		if (left < n) {
			dfs(result, level + 1, left + 1, right, n, s + "(");
		}
		if (right < left) {
			string newS(s);
			newS.append(")");
			dfs(result, level + 1, left, right + 1, n, newS);
		}
	}
	
    vector<string> generateParenthesis(int n) 
	{
		vector<string> result;
		if (n <= 0)
			return result;
		string s;
		dfs(result, 0, 0, 0, n, s);
		return result;
    }
};