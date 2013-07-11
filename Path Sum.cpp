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
    bool hasPathSum(TreeNode *root, int sum) 
	{
		if (root == NULL) {
			return false;
		}
		if (root->left == NULL && root->right == NULL && root->val == sum)
			return true;
		int leftSum = sum - root->val;
		bool leftResult = false;
		if (root->left != NULL)// special case : {}, 0; {1,2}, 1 ;
			leftResult = hasPathSum(root->left, leftSum);
		bool rightResult = false;
		if (root->right != NULL)
			rightResult = hasPathSum(root->right, leftSum);
		return (leftResult || rightResult);        
    }
};