class Solution {
public:
/**
对于每个高度，它的作用无非两个：1、以自己作高，向外扩展        2、以别人作高，自己被扩展
**/
	struct element
	{
		int id;
		int height;
		element(int _id, int _height)
		{
			id = _id;
			height = _height;
		}
	};
	
	int largestRectangleArea(vector<int> &height) 
	{
		stack<element> s;  
		int sum = 0;  
		int i = 0;
		for (i = 0; i < height.size(); i ++) 
		{  
			if (s.empty() || height[i] > s.top().height) 
				s.push(element(i, height[i]));  
            else if (s.top().height > height[i]){  
				int prev = 0;
				while (!s.empty() && s.top().height > height[i])
				{
					element e = s.top();
					s.pop();
					sum = max(sum, e.height * (i - e.id));
					prev = e.id;
				}
				s.push(element(prev, height[i]));  
            }  
		}  
		while (!s.empty())
		{
			element e = s.top();
			s.pop();
			sum = max(sum, e.height * (i - e.id));
		}
        return sum;  
	}

	// Time Limit Exceeded: 1 1 1 1 1 .... 1 1 1 s
    int largestRectangleArea1(vector<int> &height) 
	{
		if (height.size() == 0)
			return 0;
		int a[height.size()];
		for (int i = 0; i < height.size(); ++ i)
			a[i] = height[i];
        return GetBiggestRectBin(a, height.size());
        
    }
	
	int GetBiggestRectBin(int a[], int n)
	{
		if (n <= 0) return 0;

		int nMinIndex = 0;
		for (int i = 1; i < n; i++)
			if (a[nMinIndex] > a[i])
				nMinIndex = i;
		
		int nCur = a[nMinIndex] * n;
		int nLft = GetBiggestRectBin(a, nMinIndex);
		int nRgt = GetBiggestRectBin(a + nMinIndex + 1, n - 1 - nMinIndex);

		return max(nCur, max(nLft, nRgt));
	}
	
	
};

