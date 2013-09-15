/*
struct Interval {
    int start;   //区间左端点
    int end;   //区间右端点
};
*/
struct IntervalID
{
	Interval interval;
	int id;
};
// compare 不能只比较一边
bool compare1(const IntervalID &first, const IntervalID &second)
{
	if (first.interval.end < second.interval.end)
		return true;
	return false;
}

bool compare(const IntervalID &first, const IntervalID &second)
{
	if (first.interval.start != second.interval.start)
		return first.interval.start < second.interval.start;
	else return first.interval.end < second.interval.end;
}

// intervals包含n个区间
// 结果存放到isIntersected中(已分配空间,不需要push_back)
// isIntersected[i]表示第i个区间是否与其它区间相交
void intersected(vector<Interval> &intervals, vector<bool> &isIntersected) 
{
	int n = intervals.size();
	if (intervals.empty())
		return;
	vector<IntervalID> intervalsWithID;
	for (int i = 0; i < n; ++ i)
	{
		IntervalID intervalid;
		intervalid.interval = intervals[i];
		intervalid.id = i;
		intervalsWithID.push_back(intervalid);
		isIntersected[i] = false;
	}
	sort(intervalsWithID.begin(), intervalsWithID.end(), compare);
	// 使用一个线段表示当前相交的线段总长
	// 如果只比较一端的话，会有特殊情况无法排除
	int maxEnd = intervalsWithID[0].interval.end;
	int maxEndID = intervalsWithID[0].id; // 不是0！！
	for (int i = 1; i < n; ++ i)
	{
		IntervalID intervalid = intervalsWithID[i];
		if (intervalid.interval.start <= maxEnd) {			
			isIntersected[intervalid.id] = true;
			isIntersected[maxEndID] = true;
			maxEnd = max(intervalid.interval.end, maxEnd);
		} else {
			maxEndID = intervalid.id;
			maxEnd = intervalid.interval.end;
		}
		
	}
}