/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // note: the nodes of left subtree are all less than the root.
class Solution 
{
public:
    bool isValidBST(TreeNode *root) 
	{
       if (root == NULL)
			return true;
		
		return isValidBST(root, INT_MIN, INT_MAX);
				
    }
	
	bool isValidBST(TreeNode *node, int MIN, int MAX)
	{
		if (node == NULL)
			return true;
		if (node->val > MIN && node->val < MAX
				&& isValidBST(node->left, MIN, node->val)
				&& isValidBST(node->right, node->val, MAX))
			return true;
		else
			return false;
	}
};