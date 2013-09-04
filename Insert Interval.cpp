/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution 
{
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
	{
		vector<Interval> result;
		if (intervals.empty()) {
			result.push_back(Interval(newInterval.start, newInterval.end));
			return result;
		}
		int i = 0;
		int start = newInterval.start, end = newInterval.end;
		bool isInsert = false;
		for (; i < intervals.size(); ++ i)
		{
			Interval temp = intervals[i];
			if (temp.end < start)
				result.push_back(temp);
			else {
				if (temp.start > end) {
					// insert / merge
					if (!isInsert) {
						result.push_back(Interval(start, end));
						isInsert = true;
					}
					result.push_back(temp);
				} else {
					start = (start < temp.start ? start : temp.start);
					end = (end > temp.end ? end : temp.end); 
				}
			}
		}
		if (!isInsert)
			result.push_back(Interval(start, end));
		return result;
    }
};

/**
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) 
	{
        int insertp = findPosition(intervals, newInterval);
        intervals.insert(intervals.begin() + insertp, newInterval);
        for (int i = 0; i < intervals.size() - 1; ++i) {
            if (intervals[i].end >= intervals[i + 1].start) {
                if (intervals[i].end < intervals[i + 1].end) {
                    intervals[i].end = intervals[i + 1].end;
                }
                intervals.erase(intervals.begin() + i + 1);
                --i;
            }
        }
        return intervals;
    }

    int findPosition(vector<Interval> &intervals, Interval newInterval) {
        int low = 0;
        int high = intervals.size() - 1;
        while (low <= high) 
		{
            int mid = (low + high) / 2;
            if (intervals[mid].start == newInterval.start) return mid;
            else if (intervals[mid].start < newInterval.start) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};

**/

/**
1:       vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {            
2:            vector<Interval>::iterator it = intervals.begin();  
3:            while(it!= intervals.end())  
4:            {  
5:                 if(newInterval.end<it->start)  
6:                 {  
7:                      intervals.insert(it, newInterval);  
8:                      return intervals;  
9:                 }  
10:                 else if(newInterval.start > it->end)  
11:                 {  
12:                      it++;  
13:                      continue;  
14:                 }  
15:                 else  
16:                 {  
17:                      newInterval.start = min(newInterval.start, it->start);  
18:                      newInterval.end = max(newInterval.end, it->end);  
19:                      it =intervals.erase(it);                      
20:                 }                 
21:            }  
22:            intervals.insert(intervals.end(), newInterval);            
23:            return intervals;            
24:       }


**/