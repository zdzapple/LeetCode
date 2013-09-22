/**
细心。刚开始没有添加start和end参数，添加玩之后，substr的下标要改回来，不是从0开始。
**/
bool isValidateNumber(string expr)
{
	int n = expr.size();
	if (expr[0] == '0' && n > 1)
		return false;
	if (n == 0)
		return false;
	return true;
}

bool validate(const string& expr, int start, int end)
{
	if (start > end || start < 0 || end > expr.size() - 1)
		return false;
	int parentheses = 0;
	int leftParenthesesIndex = -1, rightParenthesesIndex = -1;
	int notationIndex = -1;
	int num = 0;
	for (int i = start; i <= end; ++ i)
	{
		if (expr[i] == '(') {
			if (parentheses == 0)
				leftParenthesesIndex = i;
			parentheses ++;
		}
		else if (expr[i] == ')'){
			if (parentheses == 0) {
				return false;
			}
			parentheses --;
			if (parentheses == 0)
				rightParenthesesIndex = i;
		} else if (expr[i] == '+' || expr[i] == '-')
			notationIndex = i;
		else
			num = num * 10 + (expr[i] - '0');
	}

	if (parentheses != 0) {
	    return false;
	}

	if (leftParenthesesIndex != -1) {
		string firstStr = "", secondStr = "";
		if (leftParenthesesIndex > start) {
			if (expr[leftParenthesesIndex - 1] != '+' && expr[leftParenthesesIndex - 1] != '-')
				return false;
            if (leftParenthesesIndex - 2 < start)
                return false;
			firstStr = expr.substr(start, leftParenthesesIndex - 1);
		}
		if (rightParenthesesIndex < end) {
			if (expr[rightParenthesesIndex + 1] != '+' && expr[rightParenthesesIndex + 1] != '-')
				return false;
            if (rightParenthesesIndex + 2 > end) // 1+(2+3)+
                return false;
			secondStr = expr.substr(rightParenthesesIndex + 2, end - rightParenthesesIndex - 1);
		}
		bool valid = true;

        if (firstStr != "") {
            valid = validate(expr, start, leftParenthesesIndex - 2);
            //cout << valid << " firstStr: " << firstStr <<  endl;
        }
		if (valid) {
			valid = validate(expr, leftParenthesesIndex  + 1, rightParenthesesIndex - 1);
			cout << "validate mid :" << expr[leftParenthesesIndex  + 1] << expr[rightParenthesesIndex - 1] << endl;
		}
		if (secondStr != "" && valid) {
			//valid = validate(expr, rightParenthesesIndex + 2, end);

		}

		return valid;

	} else {

		if (notationIndex != -1) {
			return validate(expr, start, notationIndex - 1) && validate(expr, notationIndex + 1, end);
		}
	}
	return isValidateNumber(expr.substr(start, end - start + 1));
}

bool validate(const string& expr)
{
	return validate(expr, 0, expr.size() - 1);

}