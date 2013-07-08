class Solution 
{
public:
    int maxProfit(vector<int> &prices) 
	{
       if (prices.empty())
			return 0;
		int minPrice = prices[0];
		int size = prices.size();
		int diff = 0;
		int result = 0;
		for (int i = 1; i < size; ++ i)
		{
			if (prices[i] >= prices[i-1]) {
				if (i == size - 1) { // don't forget
					result += (prices[size-1] - minPrice);
				}
			} else {
				result += (prices[i-1] - minPrice);
				minPrice = prices[i];
			}	
		}
		
        return result;
		
        
    }
};