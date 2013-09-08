/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int maxHeight(TreeNode *root)
	{
		if (root == NULL)
			return 0;
		int left = maxHeight(root->left) + 1;
		int right = maxHeight(root->right) + 1;
		return left > right ? left : right;
	}
	
    bool isBalanced(TreeNode *root) 
	{
        if (root == NULL)
			return true;
		int left = maxHeight(root->left);
		int right = maxHeight(root->right);
		if (abs(left - right) > 1)
			return false;
		return isBalanced(root->left) && isBalanced(root->right);
        
    }
};
/*
bool isBalanced(TreeNode *root)
{
	if (root == NULL)
		return true;
	int depth = 0;
	return isBalanced(root, &depth);
}

bool isBalanced(TreeNode *root, int *depth)
{
	if (root == NULL) {
		*depth = 0;
		return true; 
	}
	int left, right;
	if (isBalanced(root->left, &left) && isBalanced(root->right, &right)) {
		int diff = left - right;
		if (abs(diff) <= 1) {
			*depth = 1 + max(left, right);
			return true;
		}
	}
	return false;
}
*/