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
	void inorderTraversal(TreeNode *root, vector<int> &num)
	{
		if (root == NULL)
			return;
		inorderTraversal(root->left, num);
		num.push_back(root->val);
		inorderTraversal(root->right, num);
	}
	
    vector<int> inorderTraversal(TreeNode *root) 
	{   
		vector<int> result;
		inorderTraversal(root, result);
		return result;
    }
};