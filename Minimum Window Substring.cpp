class Solution 
{
public:
    string minWindow(string S, string T) 
	{
        int sLen = S.size();
		int tLen = T.size();
		int needToFind[256] = {0};
		// hash the T string
		for (int i = 0; i < tLen; ++ i)
			needToFind[T[i]] ++;
		
		int hasFound[256] = {0}; // current count of chars in current window
		int minWindowLen = INT_MAX;
		int count = 0;
		int minWindowBegin, minWindowEnd;
		// two pointers - begin & end - to scan S
		for (int begin = 0, end = 0; end < sLen; ++ end)
		{
			// skip the chars that not in T
			if (needToFind[S[end]] == 0)
				continue;
			hasFound[S[end]] ++;
			if (hasFound[S[end]] <= needToFind[S[end]])
				count ++;
			if (count == tLen) {
				// find a valid window
				// advace begin index as far as possible
				while (needToFind[S[begin]] == 0 ||
					hasFound[S[begin]] > needToFind[S[begin]])
				{
					if (hasFound[S[begin]] > needToFind[S[begin]])
						hasFound[S[begin]] --;
					begin ++;
				}
				
				int windowLen = end - begin + 1;
				if (windowLen < minWindowLen) {
					minWindowLen = windowLen;
					minWindowBegin = begin;
					minWindowEnd = end;
				}
			}
		}
        return minWindowLen == INT_MAX ? "" : S.substr(minWindowBegin, minWindowLen);
    }
};