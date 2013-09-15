/*
树结点的定义(请不要在代码中定义该类型)
struct TreeNode {
    int val;
    vector<TreeNode*> children;  //该结点的儿子结点
 };
*/
#include <functional>
int maxTreePathSum(TreeNode *root, int &maxPathSum)
{
	if (root == NULL) {
		maxPathSum = max(maxPathSum, 0);
		return 0;
	}
	vector<TreeNode*> children = root->children;
	
	if (children.empty()) {
		maxPathSum = max(maxPathSum, root->val);
		return max(root->val, 0);
	}
	vector<int> childrenSum;
	for (vector<TreeNode*>::iterator it = children.begin(); it != children.end(); ++ it)
	{
		childrenSum.push_back(maxTreePathSum(*it, maxPathSum));
	}
	int crossRootSum = root->val;
	int returnSum = root->val;
	sort(childrenSum.begin(), childrenSum.end(), greater<int>());
	if (childrenSum.size() >= 2) {
		crossRootSum += childrenSum[0] + childrenSum[1]; 
	}
	else {
		crossRootSum += childrenSum[0];
		
	}
	maxPathSum = max(maxPathSum, max(crossRootSum, max(childrenSum[0], max(childrenSum[0] + root->val, root->val))));
	returnSum = max(returnSum, returnSum + childrenSum[0]);
	
	return returnSum;
}

int maxTreePathSum(TreeNode *root) 
{
	int maxPathSum = 0;
	maxTreePathSum(root, maxPathSum);
	return maxPathSum;
}