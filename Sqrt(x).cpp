class Solution 
{
public:
    int sqrt(int x) 
	{
		long long left = 0;
		long long right = x / 2 + 1;
		while (left <= right)
		{
			long long mid = (left + right) / 2;
			long long sq = mid * mid;
			if (sq == x) return mid;
			else if (sq < x) left = mid + 1;
			else right = mid - 1;
		}
		return right;        
    }
};

/**
牛顿迭代法
计算x2 = n的解，令f(x)=x2-n，相当于求解f(x)=0的解，如左图所示。

   首先取x0，如果x0不是解，做一个经过(x0,f(x0))这个点的切线，与x轴的交点为x1。

   同样的道理，如果x1不是解，做一个经过(x1,f(x1))这个点的切线，与x轴的交点为x2。

   以此类推。

   以这样的方式得到的xi会无限趋近于f(x)=0的解。

   判断xi是否是f(x)=0的解有两种方法：

   一是直接计算f(xi)的值判断是否为0，二是判断前后两个解xi和xi-1是否无限接近。

 

经过(xi, f(xi))这个点的切线方程为f(x) = f(xi) + f’(xi)(x - xi)，其中f'(x)为f(x)的导数，本题中为2x。令切线方程等于0，即可求出xi+1=xi - f(xi) / f'(xi)。

继续化简，xi+1=xi - (xi2 - n) / (2xi) = xi - xi / 2 + n / (2xi) = xi / 2 + n / 2xi = (xi + n/xi) / 2。

有了迭代公式，程序就好写了。关于牛顿迭代法，可以参考wikipedia以及百度百科。
int sqrt(int x) {
    if (x == 0) return 0;
    double last = 0;
    double res = 1;
    while (res != last)
    {
        last = res;
        res = (res + x / res) / 2;
    }
    return int(res);
}
**/