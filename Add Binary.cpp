// for more infomatin about how to add two integers by bit operation, see: http://blog.csdn.net/walkinginthewind/article/details/6886489
http://blog.csdn.net/zhongjiekangping/article/details/6855864
class Solution 
{
public:
	string addBinary(string a, string b) 
	{
		int mLen = max(a.size(), b.size());
		int aLen = a.size();
		int bLen = b.size();
		std::reverse(a.begin(), a.end());
		std::reverse(b.begin(), b.end());
		string result;
		int carry = 0;
		int num;
		for (int i = 0; i < mLen; ++ i)
		{
			int ac, bc;
			if (i >= aLen)
				ac = 0;
			else
				ac = a[i] - '0';
			if (i >= bLen)
				bc = 0;
			else
				bc = b[i] - '0';	
			num = ac + bc + carry;
			carry = num / 2;
			num %= 2;
			result.insert(result.begin(), num + '0');
		}
		if (carry != 0)
			result.insert(result.begin(), carry + '0');
		return result;
	}

    string addBinary1(string a, string b) 
	{
        int aLen = a.size();
		int bLen = b.size();
		string result;
		int carry = 0;
		int num;
		while (aLen > 0 && bLen > 0)
		{
			num = (a[aLen - 1] - '0') + (b[bLen - 1] - '0') + carry;
			carry = num / 2;
			num = num % 2;
			result = char(num + '0' ) + result;
			
			aLen --;
			bLen --;
		}
		while (aLen > 0)
		{
			num = (a[aLen - 1] - '0') + carry;
			carry = num / 2;
			num = num % 2;
			result = char(num + '0' ) + result;
			
			aLen --;
		}
		while (bLen > 0)
		{
			num = (b[bLen - 1] - '0') + carry;
			carry = num / 2;
			num = num % 2;
			result = char(num + '0' ) + result;
			
			bLen --;
		}
		if (carry != 0) {
			result = char(carry + '0') + result;
		}
		return result;
        
    }
};