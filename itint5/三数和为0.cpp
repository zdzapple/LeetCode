typedef tuple<int, int, int> ABC; //存放a,b,c三元组
//返回所有满足条件的(a,b,c)三元组
vector<ABC> threeSumZero(vector<int> &arr) 
{
	vector<ABC> result;
	if (arr.size() < 3)
		return result;
	sort(arr.begin(), arr.end());
	int n = arr.size();
	for (int i = 0; i < n; ++ i)
	{
		 
		while (i > 0 && i < n && arr[i] == arr[i-1])
			i ++;
		int leftSum = 0 - arr[i];
		int beginIndex = i + 1;
		int endIndex = n - 1;
		while (beginIndex < endIndex)
		{
			bool add = false;
			bool substract = false;
			if (arr[beginIndex] + arr[endIndex] == leftSum) {
				ABC r = make_tuple(arr[i], arr[beginIndex], arr[endIndex]);
				result.push_back(r);
				beginIndex ++;
				endIndex --;
				add = true;
				substract = true;
			} else if (arr[beginIndex] + arr[endIndex] < leftSum) {
				beginIndex ++;
				add = true;
			} else {
				endIndex --;
				substract = true;
			}
			while (add && beginIndex < endIndex && arr[beginIndex] == arr[beginIndex-1])
					beginIndex ++;
			while (substract && endIndex > beginIndex && arr[endIndex] == arr[endIndex + 1])
					endIndex --;
		}
		
	}
	return result;
}