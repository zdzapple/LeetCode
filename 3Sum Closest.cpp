class Solution 
{
public:
    int threeSumClosest(vector<int> &num, int target) 
	{
		int result = INT_MAX;
        if (num.size() < 3) { 
			return result;
		}
		result = num[0] + num[1] + num[2];
		sort(num.begin(), num.end());
		for (int i = 0; i <= num.size() - 3; ++ i)
		{
			if (i > 0 && num[i] == num[i-1])
				continue;
			// using binary search or two pointers to find the left number
			int start = i + 1; 
			int end = num.size() - 1;
			while (start < end)
			{
				int sum = num[i] + num[start] + num[end];
				if (abs(sum - target) < abs(result - target))
					result = sum;
				if (sum == target)
					return result;
				else if (sum < target)
					start ++;
				else 
					end --;
			}
			
		}
        return result;
    }
};

/**
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int result = INT_MAX;
        int md;
        sort(num.begin(), num.end());
        vector<int>::iterator i, j, ub, lb;

        for(i = num.begin(); i + 2 != num.end(); ++i) {
            for(j = i + 1; j + 1 != num.end(); ++j) {
                md = (*i + *j - target) * (-1);
                lb = lower_bound(j+1, num.end(), md);
                ub = upper_bound(j+1, num.end(), md);
                if(lb == num.end()) lb--;
                if(ub == num.end()) ub--;
                if(md - *lb < *ub - md)
                    result = (result == INT_MAX || abs(result - target) > abs(*lb + *i + *j - target))?(*lb + *i + *j):(result);
                else result = (result == INT_MAX || abs(result - target) > abs(*lb + *i + *j - target))?(*ub + *i + *j):(result);
            }
        }
        return result;
    }
};

**/