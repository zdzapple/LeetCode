/**
无向图的欧拉路径：只有0或者2个度数为奇数的点
		欧拉回路：每个顶点的度数都是偶数
有向图的欧拉路径：起始顶点的出度（从这个顶点发出的有向边的数量）比入度（指向这个顶点的有向边的数量）多1，结束顶点的出度比入度少1，而其它顶点的出度和入度都相等。
		欧拉回路：以下两个之一：
		每个顶点的出度和入度都相等；
		存在一系列的（有向）环，使得图里的每一条边都恰好属于某一个环。

		
具体的转换方式为：n,m的棋盘，建一个包含n+m个顶点的图G（为了方便说明，类似二分图将其分为两列，左边n个顶点，右边m个顶点，分别代表n行和n列）。对于目标格子(i,j)，左边第i个顶点和右边第j个顶点连一条边。最后的问题其实就是问转换之后的图G是否存在欧拉欧拉回路或者欧拉路径。

证明：相邻两步为直角，其实就是从某一行变到某一列。访问图G中的一条边，意味着访问棋盘中的一个目标点。由于图G中的边只连接左边的点（代表某一行）和右边的点（代表某一列），因此访问一条边就意味着从某一行变到了某一列，也就是转直角了。

所以问题变为能否从一点出发访问G中的所有边有且仅有一次。这个就是欧拉回路问题了。
**/

//如果存在满足条件的遍历,返回true,否则返回false
bool existPath(vector<int> &x, vector<int> &y)
{
	int n = x.size();
	if (x.empty())
		return true;
	int rowNum = x[0];
	int colNum = y[0];
	int i, j;
	for (i = 0; i < n; ++  i)
	{
		if (rowNum < x[i])
			rowNum = x[i];
		if (colNum < y[i])
			colNum = y[i];
	}
	// the graoh should be connected graph
	//判断连通性
    bool xa[50] = {false};
    bool ya[50] = {false};
    xa[x[0]] = true;
    ya[y[0]] = true;
    i = 1, j = x.size() - 1;
    while (i <= j)
	{
        if(xa[x[i]] || ya[y[i]]) {
            xa[x[i]] = true;
            ya[y[i]] = true;
            i ++;
            j = x.size() - 1;
        }
        else {
            int xt = x[j], yt = y[j];
            x[j] = x[i];
            y[j] = y[i];
            x[i] = xt;
            y[i]= yt;
            j--;
        }
    }
    if (i!=x.size())
		return false;
	
	
	// the number of odd degresses should be 0 or 2
	vector<int> leftDegress(rowNum + 1, 0);
	vector<int> rightDegress(colNum + 1, 0);
	for (i = 0; i < n; ++ i)
	{
		leftDegress[x[i]] ++;
		rightDegress[y[i]] ++;
	}
	int oddDegressCount = 0;
	for (i = 0; i <= rowNum; ++ i)
	{
		if (leftDegress[i] % 2)
			oddDegressCount ++;
	}
	for (i = 0; i <= colNum; ++ i)
	{
		if (rightDegress[i] % 2)
			oddDegressCount ++;
	}
	return oddDegressCount == 0 || oddDegressCount == 2;
}