#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

/**
*  solution 1£º sort the array£¬and using binary search to find the second number 
                such that they add up to the target; - O(nlogn)
   solution 2: using hash  
**/        

void printVector(vector<int> numbers)
{
      for (vector<int>::iterator it = numbers.begin();
              it != numbers.end(); it ++) 
      {
          cout << *it << " ";
      }
      cout << endl;
}

 int linearSearch(const vector<int> &numbers, int target, int begin)
    {
        for (int i = begin; i < numbers.size(); ++ i)
            if (numbers[i] == target)
               return i;
        return -1;
    }

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
         int index1, index2;
         vector<int> result;   
         map<int, int> hashMap;
         for (int i = 0; i < numbers.size(); ++ i) {
             hashMap[numbers[i]] = i;
         }
         map<int, int>::iterator it;
         for (int i = 0; i < numbers.size(); ++ i) {
             if (numbers[i] > target)
                continue;
             if (target - numbers[i] == numbers[i]) {
                 int index2 = linearSearch(numbers, numbers[i], i + 1);
                 if (index2 != -1) {
                    result.push_back(i + 1);
                    result.push_back(index2 + 1);
                    return result;
                 }
             }  
             it = hashMap.find(target - numbers[i]);
             if (it != hashMap.end()) {
                 result.push_back(i + 1);
                 result.push_back(it->second + 1);
                 return result;
             }
         }
    }     
};

class Solution1
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
         vector<int> sortNumbers(numbers.begin(), numbers.end());
         sort(sortNumbers.begin(), sortNumbers.end());
         //printVector (sortNumbers);
         int index1, index2;
         vector<int> result;
         for (index1 = 0; index1 < numbers.size(); ++ index1)
         {
             int left = target - numbers[index1];
             // binary search
             index2 = binarySearch(sortNumbers, left);
             // cout << "left: " << left << " " << "index2: " << index2 << endl;
             if (index2 >= 0)
             {
                result.push_back(index1 + 1);  
                index2 = linearSearch(numbers, sortNumbers[index2], 0);
                if (index2 == index1)
                {
                    if (index2 < numbers.size() && numbers[index2 + 1] == left)
                       index2 += 1;
                    else 
                         continue;                         
                }              
                result.push_back(index2 + 1);
                return result;
             }
         }
         return result;
        
    }
    
    int binarySearch(const vector<int> &numbers, int target)
    {
        int begin = 0;
        //printVector(numbers);
        int end = numbers.size() - 1; 
        while (begin <= end)
        {
              int middle = (begin + end + 1) / 2;
              //cout << "begin: " << begin << " end:" << end << " middle:" << middle << endl;
              if (numbers[middle] == target)
                 return middle;
              if (numbers[middle] < target) {
                  begin = middle + 1;
              }
              else {
                  end = middle - 1;
              }

        }
        return -1;
    }

};


int main(int argc, char* argv[])
{
    Solution s;
    int a[] = {2,1,9,4,4,56,90,3}; 
    vector<int> number(a, a + sizeof(a) / sizeof(int));
    printVector(number);
    vector<int> res = s.twoSum(number, 8);
    cout << res[0] << " " << res[1] << endl;
    getchar();
}
