bool compare1(const string &str1, const string &str2) // wrong!!
/*
10 102
7 776
*/
{
	int i = 0, j = 0;
	while (i < str1.size() && j < str2.size())
	{
		int digit1 = i >= str1.size() ? 0 : str1[i] - '0';
		int digit2 = j >= str2.size() ? 0 : str2[j] - '0';
		if (digit1 == digit2)
			i ++, j++;
		else
			return digit1 > digit2;
	}
	return str1.size() < str2.size();
}

bool compare(const string &str1, const string &str2) 
{
	string s1 = str1 + str2;
	string s2 = str2 + str1;
	for (int i = 0; i < s1.size(); ++ i)
	{
		if (s1[i] == s2[i])
			continue;
		return (s1[i] > s2[i]);
	}
	return false;
}

string biggestNum(vector<string> &nums) 
{
	string result;
	sort(nums.begin(), nums.end(), compare);
	for (int i = 0; i < nums.size(); ++ i)
		result += nums[i];
	return result;
}