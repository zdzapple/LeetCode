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

/**
One might easily come up with a naive algorithm based on the 《leetcode: Best Time to Buy and Sell Stock II》 problem (I am one of them >_<), that is, find the maximum profit and second maximum profit among all the increasing intervals and add them together. This is wrong, and one counter example is: 7 9 6 1 3 2 4 7 –> [7, 9] = 2 | [1,  3] = 2 |  [2, 7] = 5, so previous algorithm will yield 2 + 5 = 7, however, obviously, (9-7) + (7-1) = 8 is a better one. This is quite different from  《leetcode: Best Time to Buy and Sell Stock II》because now we are restricted to use at most two transactions!

However, the correct solution is indeed based on some previous algorithm, it is based on a similar idea in 《leetcode: Best Time to Buy and Sell Stock》. The general approach is divide and conquer. We divide the prices into [0, i] and [i, N-1] two subsets, and get the maximum profits in [0, i] and [i, N-1]. We only need one linear scan to get maximum profits in [0, i] where i is from 0 to N-1, and a second linear scan to get profits in [i, N-1] where i is again from 0 to N-1 but in a reversed way as in the first linear scan. The linear scan algorithm is exactly the same as in 《leetcode: Best Time to Buy and Sell Stock》. Lastly, we do a third linear scan to test the sum of profit[0, i] + profit[i, N-1] where i is from 0 to N-1 and we get the global maximum profit.

**/