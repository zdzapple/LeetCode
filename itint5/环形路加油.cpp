#include <vector>
using namespace std;

int selectGasStation(const vector<int> &a, const vector<int> &g) 
{
	vector<int> f;
	if (a.size() <= 1)
		return 0;
	int size = a.size();
	int i;
	for (i = 0; i < size; ++ i)
		f.push_back(a[i] - g[i]);
	vector<int> result(2 * size + 1, -1);
	result[0] = f[0];
	int count = 0;
	i = 1;
	while (count < size && i <= 2*size)
	{
		if (result[i-1] >= 0) {
			result[i] = result[i-1] + f[i%size];
			count ++;
		} else {
			count = 0;
			result[i] = f[i%size];
		}
		i ++;
	}
	if (count == size) {
		return (i-1)%size;
	}
	return -1;
}


/**
计算辅助数组f(i),其含义为从i点开始到达i+1时，汽车所剩的油。有:
             f(i) = g(i)-d(i)
若f(i)<0 则显然从i点出发不可能完成任务。
 
 
题目的O(n)解法依赖于以下结论，在面试的时间内，要迅速发现这个规律不是一件容易的事。
从任意一个点s开始扫描,如果到点e之前汽车没油了,那么说明从s到e-1中的所有点出发，都不可能完成任务。
 
设从s点到e时，油箱中剩下的油为t(s,e). 完成不了任务，说明t(s,e)<0
证明：
显然t(s,e) = f(s) + t(s+1,e)
若从s开始是合理的，则必有f(s)>=0
因此t(s+1,e) = t(s+1,e)-f(s)
若t(s,e)<0,那么必有t(s+1,e)<0,显然从s+1开始也完成不了任务。
由此可得结论。
 
对于任意一个O(n)复杂度的DP题目，都需要类似的结论做支持，即f(n)仅与一个变量n有关，如果和两个变量相关即f(s,n)那么复杂度必定不为O(n)。
这个题目中直观看到相关的变量有起始点和终止点2个，所以要通过分析，剔除和无关的变量，消除无需计算的部分，才能得出正确结果。


之后MS又加了一面,题目是有一个环路,中间有N个加油站,加油站里面的油是g1,g2...gn,加油站之间的距离是d1,d2...dn,问其中是否能找到一个加油站,使汽车从这个加油站出发,走完全程,这个题有一个O(n)的算法,最多扫描2N次元素,就是先从任意一个点a开始扫描,如果到点b和点b-1之前汽车没油了,那么说明点a到点b-1都不是可能的解,所以只要从点b开始继续扫就可以了,直到有一个点c,从c出发能够成功返回到c,那么c就是需要的解,如果再次扫描到了点a还没有找到解则说明无解.最坏情况就是c=a-1,那么需要扫描2N-1个加油站,当然可以在第一圈扫描时记载部分结果来使第二圈扫描更快.

**/