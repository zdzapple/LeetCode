class Solution 
{
public:
// find the ith and jth elements(i < j), that maximizes Aj - Ai;
    int maxProfit(vector<int> &prices) 
	{
		if (prices.empty())
			return 0;
		int minPrice = INT_MAX;
		int size = prices.size();
		int diff = INT_MIN;
		for (int i = 0; i < size; ++ i)
		{
			if (prices[i] < minPrice)
				minPrice = prices[i];
			if (prices[i] - minPrice > diff) {
				diff = prices[i] - minPrice;
			}
		}
        return diff;
    }
};