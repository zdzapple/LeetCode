int helper(vector<int>& preorder, vector<int>& posorder, 
		int preorderBegin, int preorderEnd, int posorderBegin, int posorderEnd){
    if (preorderBegin == preorderEnd) return 1;
	if (preorder[preorderBegin+1] == posorder[posorderEnd-1]){
		return 2 * helper(preorder, posorder, preorderBegin+1, preorderEnd, posorderBegin, posorderEnd-1);
	}
	int k = posorderBegin;
	while (posorder[k] != preorder[preorderBegin+1])
		k ++; 
	return helper(preorder, posorder, preorderBegin+1,preorderBegin+1+k-posorderBegin ,posorderBegin , k)
		 * helper(preorder, posorder, preorderBegin+2+k-posorderBegin, preorderEnd, k+1, posorderEnd-1);
}

int countValidTrees(vector<int>& preorder, vector<int>& postorder) 
{
	int n = preorder.size();
    return helper(preorder, postorder, 0, n-1, 0, n-1);
}