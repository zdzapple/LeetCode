class Solution 
{
public:
	struct node
	{
		char c;
		int index;
		node(char _c, int _index) {c = _c; index = _index;}
	};
	int longestValidParentheses(string s) 
	{
        int longestValid = 0;
		if (s.empty())
			return 0;
		int beginIndex = INT_MAX;
		stack<node> st;
		for (int i = 0; i < s.size(); ++ i)
		{
			char ch = s[i];
			if (ch == '(') {
				st.push(node('(', i));			
			} else {
				if (!st.empty()) {
					node t = st.top();
					st.pop();
					beginIndex = min(beginIndex, t.index);
					if (st.empty())
						longestValid = max(longestValid, i - beginIndex + 1);
					else 
						longestValid = max(longestValid, i - st.top().index);
				} else {
					beginIndex = i + 1;
				}
				
			}
		}
        return longestValid;
    }


	// case: ()(()
	// tle
    int longestValidParentheses1(string s) 
	{
        int longestValid = 0;
		if (s.empty())
			return 0;
		int count = 0;
		stack<char> st;		
		int parentheses = 0;
		vector<int> index; // deal with the case "()(()", but tle
		for (int i = 0; i < s.size(); ++ i)
		{
			if (s[i] == '(') {
				parentheses ++;
				index.push_back(i);
			} else {
				if (parentheses != 0) {
					parentheses --;
					index.pop_back();
				}
			}
		}
		for (int i = 0; i < s.size(); ++ i)
		{
			char ch = s[i];
			for (int j = 0; j < index.size(); ++ j)
				if (index[j] == i) {
					if (count > longestValid)
						longestValid = count;
					count = 0;
					break;
				}
			if (ch == '(') {
				st.push(ch);			
			} else {
				if (!st.empty()) {
					char t = st.top();
					if (t == '(') {
						st.pop();						
						count ++;
						continue;
					} else {
					
					}
				} else {
					if (count > longestValid)
						longestValid = count;
					count = 0;
				}
			}
		}
		
		if (count > longestValid)
				longestValid = count;
        return 2 * longestValid;
    }
};

/**
class Solution {
public:
    struct node {
        char c;
        int index;
        node(char _c, int _index):c(_c), index(_index){};
    };
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.size() <= 1) return 0;
        stack<node> S;
        int maxlen = 0;
        S.push(node(')', -1));
        int lastlen = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') S.push(node('(', i));
            else {
                node tmp = S.top();
                if (tmp.c == '(') {
                    S.pop();
                    maxlen = max(maxlen, i-S.top().index);
                }
                else S.push(node(')', i));
            }
        }
        return maxlen;
    }
};

**/