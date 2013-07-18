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
		vector<int> &postorder, int postorderBegin, int postorderEnd)
	{
		if (inorderEnd - inorderBegin < 0)
			return NULL;
		TreeNode *root = new TreeNode(postorder[postorderEnd]);
		// find the rootIndex in the inorder vector
		int rootIndex = -1;
		for (int i = inorderBegin; i <= inorderEnd; ++ i)
		{
			if (inorder[i] == root->val) {
				rootIndex = i;
				break;
			}
		}
		root->left = buildTree(inorder, inorderBegin, rootIndex - 1, postorder, postorderBegin, postorderBegin + rootIndex - inorderBegin - 1);
		root->right = buildTree(inorder, rootIndex + 1, inorderEnd, postorder, postorderBegin + rootIndex - inorderBegin, postorderEnd - 1); // error: postorderBegin + rootIndex - inorderBegin -> rootIndex + 1
		return root;
	}
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) 
	{
		return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() -1);
    }
};