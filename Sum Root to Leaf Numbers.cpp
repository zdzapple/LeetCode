/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
	void sumNumbers(TreeNode *root, int current, int &result)
	{
		if (root->left == NULL && root->right == NULL) {
			current = current * 10 + root->val;
			result += current;
		}
		if (root->left != NULL) {
			int lcurrent = current * 10 + root->val;
			sumNumbers(root->left, lcurrent, result);
		}
		if (root->right != NULL) {
			int rcurrent = current * 10 + root->val;
			sumNumbers(root->right, rcurrent, result);
		}		
	}
    int sumNumbers(TreeNode *root) 
	{ 
		if (root == NULL)
			return 0;
		if (root->left == NULL && root->right == NULL)
			return root->val;
		int result = 0;
		int current = 0;
		sumNumbers(root, current, result);
		return result;
    }
};