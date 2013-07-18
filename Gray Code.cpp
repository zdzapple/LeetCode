class Solution 
{
public:
/**
n=k时的Gray Code，相当于n=k-1时的Gray Code的逆序 加上 1<<k。
Binary      :  000, 001, 010, 011, 100, 101, 110, 111
再者就是Binary Code 转换为Gray Code了。
如：
　　Binary Code ：1011 要转换成Gray Code
　　1011 = 1（照写第一位）, 1(第一位与第二位异或 1^0 = 1), 1(第二位异或第三位， 0^1=1), 0 (1^1 =0) = 1110
　　其实就等于 (1011 >> 1) ^ 1011 = 1110
**/
    vector<int> grayCode(int n) 
	{
		vector<int> result;      
		result.push_back(0);  
		for(int i=0; i< n; i++)  
		{  
			int highestBit = 1<<i;  
			int len = result.size();  
			for(int i = len-1; i>=0; i--)  
			{  
				result.push_back(highestBit + result[i]);  
			}  
		}  
		return result;  
    }
	
	vector<int> grayCode1(int n) {
        vector<int> ret;
        int count = 0x01 << n;
        for(int i = 0 ; i < count; ++i) {
            ret.push_back(i ^ (i>>1));
        }
        return ret;
    }
};