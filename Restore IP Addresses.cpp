class Solution
{
public:
	bool isNumber(const string &s)
	{
		if (s.empty())
			return false;
		if (s.size() == 1)
			return true;
		if (s[0] == '0')
			return false;
		int number = 0;
		for (int i = 0; i < s.size(); ++ i)
		{
			number = number * 10 + (s[i] - '0');
		}
		if (number >= 1 && number <= 255)
			return true;
		return false;
	}

	void restoreIpAddresses(string &s, vector<string> &current, vector<string> &result)
	{
		if (current.size() == 6) {
			if (isNumber(s)) {
				current.push_back(s);
				string r;
				for (int i = 0; i < current.size(); ++ i)
					r += current[i];
				result.push_back(r);
				current.pop_back();
			}
			return;
		}
		if (s.size() == 0 || s.size() == 1)
			return;
		for (int i = 1; i <= 3; ++ i)
		{
		    if (i > s.size()) // or it will get "substr out of range" error
                return;
			string str = s.substr(0, i);
			if (isNumber(str)) {
				current.push_back(str);
				current.push_back(".");
				string left = s.substr(i);
				restoreIpAddresses(left, current, result);
				current.pop_back();
				current.pop_back();
			}
		}
	}

    vector<string> restoreIpAddresses(string s)
	{
		vector<string> result;
		vector<string> current;
		if (s.empty())
			return result;
		restoreIpAddresses(s, current, result);
		return result;
    }
};