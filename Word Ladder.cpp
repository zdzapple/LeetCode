#include <iostream>
#include <limits.h>
#include <string>
#include <set>
using namespace std;

class Solution
{
public:
	// dfs Time Limit Exceeded
	// using bfs
	int ladderLength(string start, string end, unordered_set<string> &dict)
	{
		/*int minDistance = ladderLengthDFS(start, end, dict, 0);
		if (minDistance != INT_MAX)
			return minDistance + 1;
		else
			return 0;*/
		
		if (start.size() != end.size())  
            return 0;  
        if (start.empty() || end.empty() || dict.empty())  
            return 0;  
		if (start == end)
			return 1;
		return ladderLengthBFS(start, end, dict);
		
	}

	bool isOneWordDiff(string one, string two)
	{
		int diff = 0;
		for (int i = 0; i < one.size(); ++ i)
		{
			if (one[i] != two[i]) {
				diff ++;
				if (diff > 1)
					return false;
			}
		}
		return diff == 1;
	}
	
	int ladderLengthBFS(string start, string end, unordered_set<string> &dict)
	{
		queue<string> que;
		int distance = 1;
		int nextLevelNum = 0; // the number of next level's nodes
		int curLevelNum = 1;
		unordered_set<string> visited;
		
		que.push(start);
		visited.insert(start);
		
		while (!que.empty())
		{
			string curStr = que.front();
			que.pop();
			curLevelNum --;
			
			for (int i = 0; i < curStr.size(); ++ i)
			{
				char temp = curStr[i];
				for (char ch = 'a'; ch <= 'z'; ++ ch)
				{
					if (temp == ch) continue;
					string str(curStr);
					str[i] = ch;
					if (str == end)
							return distance + 1; 
					if (dict.count(str) > 0 && visited.count(str) == 0) {
						visited.insert(str);
						que.push(str);
						nextLevelNum ++;									
					}
				}
			}
			
			if (curLevelNum == 0) { // note: it's '==' not '='
				distance ++;
				curLevelNum = nextLevelNum;
				nextLevelNum = 0;
			}
			
		}
		return 0;
	}
	
	int ladderLengthDFS(string start, string end, unordered_set<string> &dict, int currentLevel)
	{
		if (dict.empty())
			return INT_MAX;
		// find end in the dict
		// unordered_set<string>::iterator it ;= dict.find(start);
		/* if (it != dict.end())
			dict.erase(start);*/

		// search
		int minLength = INT_MAX;
		// for (it = dict.begin(); it != dict.end(); ++ it) note: no iterator!! because we want change the set.
		for (int i = 0; i < start.size(); ++ i)
		{
			char temp = start[i];
			for (char ch = 'a'; ch <= 'z'; ++ ch) 
			{
				if (temp == ch) 
					continue;

				start[i] = ch;
				
				
				if (start == end)
					return currentLevel + 1;
				if (dict.count(start) > 0) {
					dict.erase(start);
					int length = ladderLengthDFS(start, end, dict, currentLevel + 1); // note: no ++currentLevel
					if (length < minLength)
						minLength = length;
					dict.insert(start);

				}
			}
			start[i] = temp;
			
		}
		return minLength;

	}
};

int main()
{
	string begin = "hot";
	string end = "dog";
	string str[] = {"hot","cog","dog","tot","hog","hop","pot","dot"};
	unordered_set<string> dict(str, str + 8);
	Solution s;
	int minLength = s.ladderLength(begin, end, dict);
	cout << minLength << endl;
	return 0;
}
