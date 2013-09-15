class Solution 
{
public:
/**
在当前序列中，从尾端往前寻找两个相邻元素，前一个记为*i，后一个记为*ii，并且满足*i < *ii。然后再从尾端寻找另一个元素*j，如果满足*i < *j，即将第i个元素与第j个元素对调，并将第ii个元素之后（包括ii）的所有元素颠倒排序，即求出下一个序列了。

1.从数列的右边向左寻找非递减序列,
    例如对于:1,3,5,4,2，红色部分即为非递减序列
2.从非递减序列里找一个比它前面的数（3）大的最小数（4），并将且交换这两个数
   即：1,3,5,4,2 => 1,4,5,3,2
3.将新的最小递减序列逆序


1.Find out the first ascending pair from the end of the list.
Taking the list [2,3,1] as example, we found the 2<3.
Assuming the index of first element as i, the latter as j. Each time when j=i+1, reset the j to the end of list and --i.
Turn to step 4 is not found.
1.从后往前寻找第一个升序（严格的），比如[2,3,1]，就找到2<3。记升序中前面那一个的下标为i。如果找不到，跳转到4.
2.if i >= 0, swap the number at indexes i and j.
After this done, the elements after i is also in descending order.
2.如果i >= 0, 交换num[i]和num[j]。
—-这一步完成之后，i后面的数仍然是降序排好序的.
3.Reverse the elements after i. And return.
3.将i之后的部分逆转，程序返回。
4.If no ascending pair is found, that means the given list is well sorted in the descending order. In this case, just reverse the whole list as required in this problem.
4.如果没有找到升序，说明整个序列都是降序排序的，就意味着这个序列是排列中的最后一个序列了。直接逆转所有元素，成为升序序列返回（第一个排列）。
**/
	void reverse(vector<int> &num, int s, int e) 
	{
		if(s > e) return;
		if(e >= num.size()) return;
		int count = e - s + 1;
		int times = count / 2;
		for(int i = 0; i < times; ++i) 
		{
			int is = s + i;
			int ie = e - i;
			int temp = num[is];
			num[is] = num[ie];
			num[ie] = temp;
		}
	}
    void nextPermutation(vector<int> &num) 
	{
		if (num.size() <= 1)
			return;
		int i = num.size() - 2;
		for(; i >= 0; --i) 
		{
			if(num[i] < num[i+1]) 
			{
			//find the last one who greater than num[i]
				for(int j = num.size() - 1; j > i; --j) 
				{
					// swap i and j
					if(num[j] > num[i]) {
						int temp = num[i];
						num[i] = num[j];
						num[j] = temp;
						break;
					}
				}
				// reverse the items from i + 1 to num.size()-1
				reverse(num, i+1, num.size()-1);
				return;
			}
		}
		  //no acending order found, reverse all the numbers
		reverse(num, 0, num.size()-1);
    }
};