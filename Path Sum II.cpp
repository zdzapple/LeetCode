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
	void pathSum(TreeNode *root, int sum, vector<int> &path, vector<vector<int> > &result)
	{
		if (root == NULL) {
			return;
		}
		if (root->left == NULL && root->right == NULL && root->val == sum) {
			path.push_back(root->val);
			result.push_back(path);
			path.pop_back();
			return;
		}
		int leftSum = sum - root->val;
		path.push_back(root->val);
		if (root->left != NULL)
			pathSum(root->left, leftSum, path, result);
		if (root->right != NULL)
			pathSum(root->right, leftSum, path, result);
		path.pop_back();
	}
	
    vector<vector<int> > pathSum(TreeNode *root, int sum) 
	{
        vector<vector<int> > result;
		vector<int> path;
		pathSum(root, sum, path, result);
		return result;
        
    }
};