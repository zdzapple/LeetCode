/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /**
	首先要从低向上考虑
	如果有    1
			 / \
			-2  5
		    /
		   7
	的情况，使用maxSum保存当前的最大值，maxPathSum返回加上root的最大值（如果最上面的1比-2大，那么整棵树都要返回，这个时候max就是函数返回的值）
	另外注意题目要求maximum path sum，即和最大的path，所以函数的return是返回一边的值（http://blog.csdn.net/u011095253/article/details/9221167）
 **/
class Solution 
{
public:
	int maxPathSum(TreeNode *root, int &maxSum)
	// return the maxSum that end by root
	{
		if (root == NULL)
			return 0;
		/*if (root->left == NULL && root->right == NULL)
			return root->val;*/ // if do this, then maxSum can't reach the leaf node
		int left = maxPathSum(root->left, maxSum);
		int right = maxPathSum(root->right, maxSum);
		int maxSumRoot = root->val;
		if (left > 0) maxSumRoot += left;
		if (right > 0) maxSumRoot += right;
		maxSum = max(maxSum, maxSumRoot);
		
		return max(root->val, max(root->val + left, root->val + right)); // maximum path sum
	}
	
    int maxPathSum(TreeNode *root) 
	{
		if (root == NULL)
			return 0;
		int maxSum = root->val;
		maxPathSum(root, maxSum);
		return maxSum;
        
    }
};