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
    TreeNode *sortedArrayToBST(vector<int> &num) 
	{
        TreeNode *root = NULL;
		if (num.empty())
			return root;
		int size = num.size();
		if (size == 1)
			return new TreeNode(num[0]);
		int middle = size / 2;
		root = new TreeNode(num[middle]);
		vector<int> leftVector(num.begin(), num.begin() + middle);
		vector<int> rightVector(num.begin() + middle + 1, num.end());
		TreeNode *left = sortedArrayToBST(leftVector);
		TreeNode *right = sortedArrayToBST(rightVector);
		root->left = left;
		root->right = right;
		return root;
        
    }
};