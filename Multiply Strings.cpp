class Solution 
{
public:
    string multiply(string num1, string num2) 
	{
        if (num1.size() == 0 || num2.size()  == 0) 
			return 0;
		string res(num1.size() + num2.size() + 1, '0');
		for (int i = num2.size() - 1; i >= 0; -- i)
		{
			int carry = 0;
			int digit1 = num2[i] - '0';
			for (int j = num1.size() - 1; j >= 0; -- j)
			{
				int digit2 = num1[j] - '0';
				int preResult = res[num2.size()-i-1+num1.size()-j-1] - '0';
				int multip = (digit1 * digit2 + preResult + carry);
				res[num2.size()-i-1+num1.size()-j-1] = multip % 10 + '0';
				carry = multip / 10;
			}
			if (carry > 0) {
				int preResult = res[num1.size() + num2.size()-i-1]  - '0';
				res[num1.size() + num2.size()-i-1] = (preResult + carry) + '0';
			}
		}
        std::reverse(res.begin(), res.end());  
		int start =0;  
		while(res[start] =='0' && start < res.size())  
		{  
			start ++;  
		}  
		if (start == res.size()) return "0";  
		return res.substr(start, res.size()-start);  
    }
};
/**
another way :
reverse num1 and num2 at the begining.
**/