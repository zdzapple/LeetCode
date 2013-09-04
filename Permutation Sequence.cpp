class Solution 
{
public:
// TLE
    string getPermutation1(int n, int k) 
	{
        vector<int> num(n);
		for (int i = 0; i < n; ++ i)
			num[i] = i+1;
		
		for (int i = 1; i < k; ++ i)
			next_permutation(num.begin(), num.end());
		string str = "";
		for (int i = 0; i < n; ++ i)
			str += ('0' + num[i]);
        return str;
    }
	
	string getPermutation(int n, int k) 
	{
        vector<int> num(n);
		int permCount = 1;
		for (int i = 0; i < n; ++ i)
		{	
			num[i] = i + 1;
			permCount *= (i + 1);
		}
		k --;
		string str;
		for (int i = 0; i < n; ++ i)
		{
			permCount = permCount / (n - i);
			int index = k / permCount;
			str.push_back(num[index] + '0');
			for (int j = index; j < n - i - 1; ++ j) // erase the chosen number
				num[j] = num[j + 1];
			k = k % permCount;
		}
		return str;
	}
};
/*
假设有n个元素，第K个permutation是
a1, a2, a3, .....   ..., an
那么a1是哪一个数字呢？

那么这里，我们把a1去掉，那么剩下的permutation为
a2, a3, .... .... an, 共计n-1个元素。 n-1个元素共有(n-1)!组排列，那么这里就可以知道

设变量K1 = K
a1 = K1 / (n-1)!

同理，a2的值可以推导为
a2 = K2 / (n-2)!
K2 = K1 % (n-1)!
 .......
a(n-1) = K(n-1) / 1!
K(n-1) = K(n-2) /2!
*/