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