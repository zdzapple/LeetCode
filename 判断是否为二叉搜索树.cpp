/*
树结点的定义(请不要在代码中定义该结构)
struct TreeNode {
  int val;
  TreeNode *left, *right;
}*/
bool isBST(TreeNode *root, int minValue, int maxValue)
{
	if (root == NULL)
		return true;
	if (root->val >= minValue && root->val < maxValue) {
		return isBST(root->left, minValue, root->val) &&
					isBST(root->right, root->val, maxValue);
	}
	return false;
}

bool isBST(TreeNode *root) 
{
	int minValue = -999999999;//INT_MIN;
	int maxValue = 999999999;//INT_MAX;
	return isBST(root, minValue, maxValue);
}