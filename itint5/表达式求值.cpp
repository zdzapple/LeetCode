//返回表达式expr的值
int evaluate(const string& expr, int start, int end)
{
	if (start > end)
		return 0;
	int plusIndex = -1, multiIndex = -1;
	int sigh = 1, num = 0;
	for (int i = start; i <= end; ++ i)
	{
		if (expr[i] == '+' || expr[i] == '-')
            plusIndex = i, sigh = expr[i] == '+' ? 1 : -1;
        else if (expr[i] == '*')
            multiIndex = i;
        num = num * 10 + expr[i] - '0';
	}
	if (plusIndex != -1) return evaluate(expr, start, plusIndex - 1) + sigh * evaluate(expr, plusIndex + 1, end);
    if (multiIndex != -1) return evaluate(expr, start, multiIndex - 1) * evaluate(expr, multiIndex + 1, end);
    return num;
}

int evaluate(const string& expr) 
{
	return evaluate(expr, 0, expr.size() - 1);
}


/**
int getNum(const string &s, size_t &i) {
    int n=0;
    for (; i<s.size(); ++i){
        if (s[i]<'0' || s[i]>'9') break;
        n = 10*n+s[i]-'0';
    }
    return n;
}

int helper(const string &s, int m, size_t i) {
    int n = getNum(s, i);
    if (i>=s.size()) return m*n;
    if (s[i]=='*')   return helper(s, m*n, i+1);
    else             return m*n+helper(s, s[i]=='+'?1:-1, i+1);
}

int evaluate(string expr) {
    return helper(expr, 1, 0);
}

**/