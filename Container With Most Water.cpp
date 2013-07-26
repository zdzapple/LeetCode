class Solution 
{
public:
	int maxArea(vector<int> &height) 
	{
		if (height.empty())
			return 0;
		int max = 0;
		int i = 0; 
		int j = height.size() - 1;
		while (i < j)
		{
			int area = 0;
			if (height[i] < height[j]) {
				area = height[i] * (j - i);
				i ++;
				// sine height[i] is lower than height[j]
				// there will be no j' < j than the area between i..j' is larger than the area between i and j
				// so advance the i to find weather there a larger one
			} else {
				area = height[j] * (j - i);
				j --;
			}
			if (max < area) 
				max = area;
		}
		return max;
	}
	
	// normal way
    int maxAreaN2(vector<int> &height) 
	{
		if (height.empty())
			return 0;
        int max = 0;
		for (int i = 0; i < height.size(); ++ i)
		{
			if (height[i] == 0)
				continue;
			int minPossibleIndex = max / height[i] + i;
			for (int j = height.size() - 1; j > i && j >= minPossibleIndex; -- j)
			{
				int area = min(height[i], height[j]) * (j - i);
				if (max < area)
					max = area;
			}
		}
        return max;
    }
};

/**
(1) Brute force approach: compare every pair of lines to calculate the area between these two lines, keep the max among the O(N^2) pairs, the time complexity is obviously O(N^2) and you might get a TLE error when testing on the big dataset.

(2) Sorting: make a pair for each line as <height, index>, so there would be N such pairs as <a1, 1> <a2, 2>, …, <aN, N>. Sort these N pairs by increasing order on the height value (so ai is in increasing order). Now you can think about how this sort could help before heading into the following context (hint: remember the “Best Time to Buy and Sell Stock” problem, essentially, the solution becomes the same here). Ok, here is the answer, let F(i) denote the max water among the pairs from i-th pair to the last pair after sorting. Now we consider F(i-1), when adding the (i-1)th pair, we need to update the max water, how? since the height is in increasing order, then the (i-1)th pair here must have the shortest line, and the possible amount of water much be this (shortest) height times the difference of indexes between the index value of this (i-1)th pair and the index value among the pairs after. These computation could be done in constant time by keep recording of the minimum index and the maximum index among the pairs after (i-1)th pair. If you check the best time to buy and sell stock problem out, the approach after sorting here is essentially the same one. The total time complexity is O(NlogN + N) = O(NlogN).
(when caclulating the maximum differnce of indexes, we can use dp. dp[i] = pair<i+1>.index or dp[i+1])

(3) Linear approach: If there is no linear approach, then I really think the sorting method is good enough to show your coding ability and knowledge on algorithm. However, there is a even smarter approach though it is not easy to come up with. Basically, we use two pointers say i and j to point to the head and the tail of the original height array. We first calculate the area between line i and line j and try to update the max area if possible. Then we check the lin[i] and lin[j], and advance the pointer to the shorter line by one step (++i or –j). After a linear scan like this, we make sure the max area is found correctly. The idea behind is that, if we encounter a shorter line, say line[i] is shorter than line[j], then there is no need to check other pairs with line[i], if we move j (–j), then the area must only be smaller (why? think about it). The same reasoning applies here for the case where line[j] is shorter. Obviously, this approach takes linear time which is O(N).


**/