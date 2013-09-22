//返回a+b的结果
string add(const string& a, const string& b) 
{
	if (a.empty())
		return b;
	if (b.empty())
		return a;
	int m = a.size();
	int n = b.size();
	if (m < n)
		return add(b, a);
		
	string result(m + 1, '0');
	int i = m - 1;
	int j = n - 1;
	int carry = 0;
	int resultIndex = 0;
	while (j >= 0)
	{
		int addResult = (a[i] - '0') + (b[i] - '0') + carry;
		carry = addResult / 10;
		addResult %= 10;
		result[resultIndex ++] = '0' + addResult;
		i --;
		j --;
	}
	while (i >= 0) 
	{
		int addResult = (a[i] - '0') + carry;
		carry = addResult / 10;
		addResult %= 10;
		result[resultIndex ++] = '0' + addResult;
		i --;
	}
	if (carry > 0)
		result[resultIndex] = '0' + carry;
	reverse(result.begin(), result.end());
	int start = 0;
	while (start < result.size() && result[start] == '0')
		start ++;
	if (start == result.size())
		return "0";
	return result.substr(start);
}