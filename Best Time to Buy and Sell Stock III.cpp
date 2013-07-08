class Solution 
{
public:
	int maxProfit(vector<int> &prices) 
	{
		if (prices.empty())
			return 0;
		// using a vector store the max profit
		vector<int> maxEndWith;
		int diff = 0;
		int minPrice = prices[0];
		maxEndWith.push_back(0);
		for (int i = 1; i < prices.size(); ++ i)
		{
			if (prices[i] - minPrice > diff) {
				diff = prices[i] - minPrice;
			}
			maxEndWith.push_back(diff);
			if (prices[i] < minPrice)
				minPrice = prices[i];
		}
		// caculate what is the maxprofit of [i, ... , n-1] subarray in prices
		int maxPrice = prices[prices.size()-1];
		diff = 0;
		int result = 0;
		for (int i = prices.size()-2; i >= 0; --i)
		{
			if (maxPrice - prices[i] > diff) {
				diff = maxPrice - prices[i];
			}
			if (prices[i] > maxPrice)
				maxPrice = prices[i];
			if (diff + maxEndWith[i] > result)
				result = diff + maxEndWith[i];
		}
		return result;
		
    }
    int maxProfit1(vector<int> &prices) 
	// wrong answer: special case:[1,2,4,2,5,7,2,4,9,0]
	{
		if (prices.empty())
			return 0;
		int minPrice = prices[0];
		int size = prices.size();
		int diff = 0;
		vector<int> diffs(2, INT_MIN);
		for (int i = 1; i < size; ++ i)
		{
			if (prices[i] >= prices[i-1]) {
				if (i == size - 1) { // don't forget
					diff = (prices[size-1] - minPrice);
					if (diff > diffs[0])
						diffs[0] = diff;
					else if (diff > diffs[1])
						diffs[1] = diff;
				}
			} else {
				diff = (prices[i-1] - minPrice);
				minPrice = prices[i];
				if (diff > diffs[0])
					diffs[0] = diff;
				else if (diff > diffs[1])
					diffs[1] = diff;
				if (diffs[0] > diffs[1]) {
					int temp = diffs[0] ;
					diffs[0] = diffs[1];
					diffs[1] = temp;
				}
			}	
		}
		
        int result = 0;
		if (diffs[0] != INT_MIN) result += diffs[0];
		if (diffs[1] != INT_MIN) result += diffs[1];
        return result;
    }
};