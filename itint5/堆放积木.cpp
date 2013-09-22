/*积木的定义(请不要在代码中定义该结构)
struct Box {
  int vol, weight;
};*/
bool compare(const Box &box1, const Box &box2)
{
	if (box1.vol == box2.vol)
		return box1.weight < box2.weight;
	return box1.vol < box2.vol;
}

int maxBoxes(vector<Box> &boxes) 
{
	if (boxes.empty())
		return 0;
	sort(boxes.begin(), boxes.end(), compare);
	int n = boxes.size();
	vector<int> num(n, 1);
	int maxNum = 1;
	for (int i = 1; i < n; ++ i)
	{
		for (int j = i-1; j >= 0; -- j)
		{
			if (boxes[j].vol < boxes[i].vol 
				&& boxes[j].weight < boxes[i].weight) {
				num[i] = max(num[j] + 1, num[i]);
			}
		}
		maxNum = max(maxNum, num[i]);
	}
	return maxNum;
}