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
	TreeNode *buildTree(vector<int> &inorder, int inorderBegin, int inorderEnd, 
		vector<int> &preorder, int preorderBegin, int preorderEnd)
	{
		if (inorderEnd - inorderBegin < 0)
			return NULL;
		TreeNode *root = new TreeNode(preorder[preorderBegin]);
		// find the rootIndex in the inorder vector
		int rootIndex = -1;
		for (int i = inorderBegin; i <= inorderEnd; ++ i)
		{
			if (inorder[i] == root->val) {
				rootIndex = i;
				break;
			}
		}
		root->left = buildTree(inorder, inorderBegin, rootIndex - 1, preorder, preorderBegin + 1, preorderBegin + rootIndex - inorderBegin);
		root->right = buildTree(inorder, rootIndex + 1, inorderEnd, preorder, preorderBegin + rootIndex - inorderBegin + 1, preorderEnd); 
		return root;
	}
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) 
	{
        return buildTree(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() -1);        
    }
};