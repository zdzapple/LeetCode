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
	static bool less(const Interval& interval1, const Interval& interval2)
	// note: if it is declared in the class, it should be "static"
	// 		 or you can declare it outside the class.
	{
		if (interval1.start == interval2.start)
			return interval1.end < interval2.end;
		return interval1.start < interval2.start;
	}

    vector<Interval> merge(vector<Interval> &intervals) 
	{
		std::sort(intervals.begin(), intervals.end(), less);
		vector<Interval> result;
		int begin, end;
		if (intervals.size() == 0)
			return result;
		begin = intervals[0].start;
		end = intervals[0].end;
		for (int i = 1; i < intervals.size(); ++ i)
		{
			if (intervals[i].start > end) {
				Interval in(begin, end);
				result.push_back(in);
				begin = intervals[i].start;
				end = intervals[i].end;
			}
			else {
				if (intervals[i].end > end)
					end = intervals[i].end;
			}
		}
		result.push_back(Interval(begin, end));
		return result;
    }
};