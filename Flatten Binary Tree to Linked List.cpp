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
	TreeNode* preOrderTraversal(TreeNode *root)
	{
		if (root == NULL)
			return NULL;
		if (root->left == NULL && root->right == NULL)
			return root;
		TreeNode *left = NULL;
		TreeNode *right = NULL;
		if (root->left != NULL)
			left = preOrderTraversal(root->left);
		if (root->right != NULL)
			right = preOrderTraversal(root->right);
		if (left == NULL) {
			return root;
		} else {
			root->left = NULL; // do not forget...
			root->right = left;
			while (left->right != NULL) // find the leaf node of the left subtree
				left = left->right; 
			left->right = right;
			left->left = NULL;			
		}
		
		return root;
	}

    void flatten(TreeNode *root) 
	{
        if (root == NULL)
			return;
		preOrderTraversal(root);
        
    }
};