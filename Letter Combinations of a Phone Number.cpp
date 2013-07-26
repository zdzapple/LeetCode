class Solution 
{
public:
	void generate(int level, string trans[], string &digits, vector<string> &result, string &current)
	{
		if (level == digits.size()) {
			result.push_back(current);
			return;
		}
		string str = trans[digits[level] - '0'];
		for (int i = 0; i < str.size(); ++ i)
		{
			current.push_back(str[i]);
			generate(level+1, trans, digits, result, current);
			// delete the last character
			// current.resize(current.size() - 1);
			current.erase(current.size() - 1);
		}
	}

    vector<string> letterCombinations(string digits) 
	{
        vector<string> result;
		string current = "";
		string trans[] = {"", " ", "abc", "def", "ghi", "jkl",  
					"mno", "pqrs", "tuv", "wxyz"};  
		
        generate(0, trans, digits, result, current);
		return result;
    }
};