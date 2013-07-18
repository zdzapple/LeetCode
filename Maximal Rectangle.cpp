class Solution 
{
public:
// caculate the rectangle whose left-top number is '1'
// or: http://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/
    int maximalRectangle1(vector<vector<char> > &matrix) 
	{
        int result = 0;
		int m = matrix.size();
		if (m == 0)
			return 0;
		int n = matrix[0].size();
		for (int i = 0; i < m; ++ i)
		{
			for (int j = 0; j < n; ++ j)
			{
				if (matrix[i][j] == '1') {
					int area = getArea(i, j, matrix);
					if (result < area) result = area;
				}
			}
		}
        return result;
    }
	int getArea(int row, int col, vector<vector<char> > &matrix)
	{
		int m = matrix.size();
		int n = matrix[0].size();
		int maxArea = 0;
		int maxCol = n;
		for (int i = row; i < m; ++ i)
		{
			if (matrix[i][col] == '0')
				break;
			for (int j = col; j < maxCol; ++ j)
			{
				if (matrix[i][j] == '0') {
					maxCol = j;
					break;
				}
			}
			int area = (maxCol-col) * (i-row+1);
			if (maxArea < area) maxArea = area;
		}
		return maxArea;
	}
	//------
	// 与Largest Rectangle in Histogram联系起来
	int maximalRectangle(vector<vector<char> > &matrix) 
	{
		int result = 0;
		int m = matrix.size();
		if (m == 0)
			return 0;
		int n = matrix[0].size();
		vector<int> height(n, 0);
		for (int i = 0; i < m; ++ i)
		{
			for (int j = 0; j < n; ++ j)
			{
				if (matrix[i][j] == '1')
					height[j] ++;
				else
					height[j] = 0;
			}
			result = max(result, largestRectangleArea(height));
		}
		return result;
	}
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
	
};