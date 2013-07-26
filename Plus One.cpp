class Solution 
{
public:
    vector<int> plusOne(vector<int> &digits) 
	{
		vector<int> result;
        if (digits.empty()) {
			result.push_back(1);
			return result;
		}
		int n = digits.size();
		int carry = (digits[n-1] + 1) / 10;
		result.push_back((digits[n-1] + 1) % 10);		
		for (int i = n-2; i >= 0; -- i) // note: from the back to the front of the array
		{
			int digit = digits[i];			
			result.push_back((digit + carry) % 10);
			carry = (digit + carry) / 10;
		}
		if (carry)
			result.push_back(1);
        reverse(result.begin(), result.end());
		return result;
    }
};