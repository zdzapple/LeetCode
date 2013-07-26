class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
	{
        if (s.empty())
			return 0;
		int longestSubstring = 0;
		for (int i = 0; i < s.size(); ++ i)
		{
			vector<int> count(26, 0);
			count[s[i] - 'a'] ++;
			int len = 1;
			for (int j = i + 1; j < s.size(); ++ j)
			{
				if (count[s[j] - 'a'] > 0)
					break;
				else {
					len ++;
					count[s[j] - 'a'] ++;
				}
			}
			if (len > longestSubstring)
				longestSubstring = len;
		}
		return longestSubstring;
        
    }
};
/**
Make sure you communicate with your interviewer if the string can have characters other than ‘a’-'z’. (ie, Digits? Upper case letter? Does it contain ASCII characters only? Or even unicode character sets?)

a O(N) version

int lengthOfLongestSubstring(string s) {
  int n = s.length();
  int i = 0, j = 0;
  int maxLen = 0;
  bool exist[256] = { false };
  while (j < n) {
    if (exist[s[j]]) {
      maxLen = max(maxLen, j-i);
      while (s[i] != s[j]) {
        exist[s[i]] = false;
        i++;
      }
      i++;
      j++;
    } else {
      exist[s[j]] = true;
      j++;
    }
  }
  maxLen = max(maxLen, n-i);
  return maxLen;
}

**/