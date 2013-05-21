#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

// note: we can't use unique() function(use sort before unique()) because it is a 2 dim vector;
//       can use hash/set to judge whether the element is duplicate
class Solution
{
public:
//    bool compare(const vector<int> &v1, const vector<int> &v2)
//    {
//        if (v1[0] < v2[0])
//            return true;
//        else if (v1[0] == v2[0] && v1[1] < v2[1])
//            return true;
//        else if (v1[0] == v2[0] && v1[1] == v2[1] && v1[3] < v2[3])
//            return true;
//        return false;
//    }

    // see: http://www.byvoid.com/blog/string-hash-compare
    unsigned int BKDRHash(string str)
    {
        unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
        unsigned int hash = 0;

        for(int i = 0; i < str.size(); i ++)
        {
            hash = hash * seed + str[i];
        }

        return (hash & 0x7FFFFFFF);
    }

    vector<vector<int> > threeSum(vector<int> &num)
	{
		vector<vector<int> > result;
		set<vector<int> > mySet; // using set
		map<unsigned int, int> myMap;
		if (num.size() < 3) // important
			return result;
		sort(num.begin(), num.end());
		string str;
		for (int i = 0; i <= num.size() - 3; ++ i)
		{
			int a = num[i];
			int left = 0 - a;
			// find 2 numbers b&c in num[i+1..end] so that b + c = left
			int p = i + 1;
			int q = num.size() - 1;
			while (p < q)
			{
				if (num[p] + num[q] < left)
					p ++;
				else if (num[p] + num[q] > left)
					q --;
				else {
                    str.clear();
                    str += a;
                    str += num[p];
                    str += num[q];
                    unsigned int hash = BKDRHash(str);
                    if (myMap.find(hash) == myMap.end()) {
                        myMap[hash] = 1;
                        vector<int> temp;
                        temp.push_back(a);
                        temp.push_back(num[p]);
                        temp.push_back(num[q]);
                        result.push_back(temp);
                    }
                    p ++;
					q --;
//					vector<int> temp;
//					temp.push_back(a);
//					temp.push_back(num[p]);
//					temp.push_back(num[q]);
//					mySet.insert(temp);
//					// important: don't break!!
//					p ++;
//					q --;
				}
			}
		}
//		sort(result.begin(), result.end(), compare);
//		vector<vector<int> >::iterator it = unique(result.begin(), result.end());
//        if (it != result.end())
//            result.erase(it, result.end());
//        // equal:  result.resize( std::distance(result.begin(),it) );

		// using set
//		for (set<vector<int> >::iterator it = mySet.begin(); it != mySet.end();
//				++ it)
//			result.push_back(*it);

        // using hash

		return result;

    }
};

int main()
{
    Solution s;
    int a[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    vector<int> num(a, a+sizeof(a)/sizeof(int));
    vector<vector<int> > result = s.threeSum(num);
    for (int i = 0; i < result.size(); ++ i)
    {
        cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << endl;
    }
    return 0;
}
