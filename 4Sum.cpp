class Solution 
{
public:	
    vector<vector<int> > fourSum(vector<int> &num, int target) 
	{
		vector<vector<int> > results;
		int n = num.size();
		if (n < 4) return results;

		sort(num.begin(), num.end());
		int temp = 0;
		vector<int> quad(4, 0);
		int i = 0;
		while (i < n-3) 
		{
			int j = i + 1;
			while (j < n-2) 
			{
				int p = j + 1, q = n - 1;
				while (p < q) 
				{
					int sum = num[i] + num[j] + num[p] + num[q];
					if (sum == target) 
					{
						quad[0] = num[i];
						quad[1] = num[j];
						quad[2] = num[p];
						quad[3] = num[q];
						results.push_back(quad);
						while (p < q && num[++p] == quad[2]);
						while (p < q && num[--q] == quad[3]);
					}
					else if (sum < target) {
						temp = num[p];
						while (p < q && num[++p] == temp); 
					}
					else {
						temp = num[q];
						while (p < q && num[--q] == temp);
					}
				}
				temp = num[j];
				while (j < n - 2 && num[++j] == temp);
			}
			temp = num[i];
			while (i < n - 3 && num[++i] == temp);
		}
		return results;
        
    }
};

/**
using hash:  first compute the N^2 two sums, and sort the two sums. Then for each TwoSum t, we check whether there is another two sum t' such that t.value + t'.value = target. The time complexity of this approach is O(N^2 logN)
struct TwoSum
{
	int index1;
	int index2;
	int value;
	TwoSum(int idx1, int idx2, int v) : 
       index1(idx1), index2(idx2), value(v) {}
};

struct TwoSumCompare {
	bool operator() (TwoSum ts1, TwoSum ts2) 
	{ 
		if (ts1.value == ts2.value) {
			if (ts1.index1 == ts1.index1)  
				return (ts1.index2 < ts2.index2);
			else 
				return (ts1.index1 < ts2.index1);       
		}
		else 
			return (ts1.value < ts2.value);      
}
} twoSumCompare;

class Solution 
{
private:
    vector<vector<int> > result;
    vector<TwoSum> twoSum;

public:

    int find_start_index(int begin, int end, int val)
	{
		int mid;
		while (begin <= end)
		{
			mid = begin + (end - begin) / 2; 
			if (twoSum[mid].value >= val)  
				end = mid - 1;
			else  
				begin = mid + 1;             
        }
        
        return end + 1;
    }


    int find_end_index(int begin, int end, int val)
	{
		int mid;
        
        while (begin <= end)
		{
			mid = begin + (end - begin) / 2;     
			if (twoSum[mid].value <= val)  
				begin = mid + 1;
			else  
				end = mid - 1;             
        }
        
        return begin - 1;
    }


    vector<vector<int> > fourSum(vector<int> &num, int target) 
	{    
        twoSum.clear();
        result.clear();
        
        int i, j;
        for (i = 0; i < num.size(); i ++)
		{
            for (j = i + 1; j < num.size(); j ++)
			{
				TwoSum ts(i, j, num[i] + num[j]);
                twoSum.push_back( ts );
            }
        }
 
        sort(twoSum.begin(), twoSum.end(), twoSumCompare);
        
        for (i = 0; i < twoSum.size(); i ++)
		{
           int begin, end, mid;
           
           int val = target - twoSum[i].value;
            
           // As there might be i1, i2, j1, j2 such that 
           //  num[i1] + num[i2] == num[j1] + num[j2],
           // we need to find the range of the TowSums that have the same value.
           begin = find_start_index(i + 1, twoSum.size() -1, val);
           end = find_end_index(i + 1, twoSum.size() - 1, val);

           for (j = begin; j <= end; j ++)
		   {
               if (twoSum[j].index1 == twoSum[i].index1) continue;
               if (twoSum[j].index2 == twoSum[i].index1) continue;
               if (twoSum[j].index1 == twoSum[i].index2) continue;
               if (twoSum[j].index2 == twoSum[i].index2) continue;
                   
               vector<int> tmp;                   
               tmp.push_back( num[ twoSum[i].index1] );
               tmp.push_back( num[ twoSum[i].index2] );
               tmp.push_back( num[ twoSum[j].index1] );
               tmp.push_back( num[ twoSum[j].index2] );
                  
               sort(tmp.begin(), tmp.end());
                  
                if (find(result.begin(), result.end(), tmp) == result.end())
                    result.push_back(tmp);
            }
               
        
        }
        return result;
    }
};


**/