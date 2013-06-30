class Solution 
{
public:
	bool isPalindrome(const string &s)
	{
		if (s.size() == 1)
			return true;
		int i = 0;
		int j = s.size() - 1;
		while (i <= j)
		{
			if (s[i] != s[j])
				return false;
			i ++;
			j --;
		}
		return true;
	}
	
	void partition(string &s, vector<vector<string> > &result, vector<string> &current)
	{
		//if (s.size() == 1) {
		//	current.push_back(s);
		//	result.push_back(current);
		//	return;
		//}
		for (int i = 0; i <= s.size() - 1; ++ i)
		{
			string sub = s.substr(0, i + 1);
			if (isPalindrome(sub)) {
				current.push_back(sub);
				if (i == s.size() - 1) { // don't miss the whole string, like "bb"
					result.push_back(current);
					current.pop_back();
					return;
				}
				string left = s.substr(i + 1, s.size() - i - 1);
				partition(left, result, current);
				current.pop_back();
			}
		}
	}
	
    vector<vector<string>> partition(string s) 
	{
		vector<vector<string>> result;
        if (s.empty())
			return result;
		vector<string> current;
		partition(s, result, current);		
        
    }
};