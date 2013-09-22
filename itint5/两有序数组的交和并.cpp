vector<int> arrayUnion(vector<int> &a, vector<int> &b)
{
	vector<int> unionVector;
	if (a.empty() && b.empty())
		return unionVector;
	int aIndex = 0;
	int bIndex = 0;
	while (aIndex < a.size() || bIndex < b.size())
	{
		int aVal = aIndex < a.size() ? a[aIndex] : INT_MAX;
		int bVal = bIndex < b.size() ? b[bIndex] : INT_MAX;
		if (aVal == bVal) {
			unionVector.push_back(aVal);
			while (aIndex < a.size() - 1 && a[aIndex + 1] == a[aIndex])
				aIndex ++;
			aIndex ++;
			while (bIndex < b.size() - 1 && b[bIndex + 1] == b[bIndex])
				bIndex ++;
			bIndex ++;
		} else if (aVal < bVal) {
			unionVector.push_back(aVal);
			while (aIndex < a.size() - 1 && a[aIndex + 1] == a[aIndex])
				aIndex ++;
			aIndex ++;
		}
		else {
			unionVector.push_back(bVal);
			while (bIndex < b.size() - 1 && b[bIndex + 1] == b[bIndex])
				bIndex ++;
			bIndex ++;
		}
	}
	return unionVector;
}

vector<int> arrayIntersect(vector<int> &a, vector<int> &b)
{
	vector<int> intersect;
	if (a.empty() || b.empty())
		return intersect;
	int aIndex = 0;
	int bIndex = 0;
	while (aIndex < a.size() && bIndex < b.size())
	{
		if (a[aIndex] == b[bIndex]) {
			intersect.push_back(a[aIndex]);
			while (aIndex < a.size() - 1 && a[aIndex + 1] == a[aIndex])
				aIndex ++;
			while (bIndex < b.size() - 1 && b[bIndex + 1] == b[bIndex])
				bIndex ++;
			aIndex ++;
			bIndex ++;
		} else if (a[aIndex] < b[bIndex]) {
			while (aIndex < a.size() - 1 && a[aIndex + 1] == a[aIndex])
				aIndex ++;
			aIndex ++;
		}
		else {
			while (bIndex < b.size() - 1 && b[bIndex + 1] == b[bIndex])
				bIndex ++;
			bIndex ++;
		}
	}
	return intersect;
}