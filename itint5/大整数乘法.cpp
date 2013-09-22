//返回a*b的结果
string multiply(const string& a, const string& b) 
{
	if (a.empty())
		return b;
	if (b.empty())
		return a;
	if (a == "0" || b == "0")
		return "0";
	int sign = 1;
	int abeginIndex = 0, bbeginIndex = 0;
	if (a[0] == '-') {
		sign *= -1;
		abeginIndex = 1;
	} 
	if (b[0] == '-') {
		sign *= -1;
		bbeginIndex = 1;
	}
	string result(a.size() + b.size() + 1, '0');
	int carry = 0;
	for (int i = b.size() - 1; i >= bbeginIndex; -- i)
	{
		carry = 0;
		int bNum = b[i] - '0' ;
		for (int j = a.size() - 1; j >= abeginIndex; -- j)
		{
			int aNum = a[j] - '0';
			int r = result[b.size()-1-i + a.size()-j-1] - '0';
			int multiResult = aNum * bNum + r + carry;
			carry = multiResult / 10;
			multiResult %= 10;

			result[b.size()-1-i + a.size()-1-j] = '0' + multiResult;
		}
		if (carry > 0) {
			result[b.size() + a.size()-i-1-abeginIndex] = '0' + (result[b.size()-i-1+a.size()-abeginIndex] - '0' + carry);
		}
	}
	std::reverse(result.begin(), result.end());  
	int start = 0;  
	while (result[start] =='0' && start < result.size())  
	{  
		start ++;  
	}
	if (start == result.size()) return "0";  	
	result = result.substr(start);
	if (sign < 0)
		result.insert(0, "-");
	return result;
}