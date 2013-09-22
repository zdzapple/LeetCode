/*
树结点的定义(请不要在代码中定义该结构)
struct TreeNode {
  TreeNode *left;
  TreeNode *right;
}*/
bool isBalancedTree(TreeNode *root, int &height) 
{
	if (root == NULL) {
		height = 0;
		return true;
	}
	if (root->left == NULL && root->right == NULL) {
		height = 1;
		return true;
	}
	int leftHeight = 0;
	int rightHeight = 0;
	if (isBalancedTree(root->left, leftHeight) &&
			isBalancedTree(root->right, rightHeight)) {
		if (abs(leftHeight - rightHeight) <= 1) {
			height = max(leftHeight, rightHeight) + 1;
			return true;
		}
	}
	return false;
}

bool isBalancedTree(TreeNode *root) 
{
	int height = 0;
	return isBalancedTree(root, height);
}