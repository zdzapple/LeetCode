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
	vector<TreeNode *> recursion(int &n, int &beginValue)
	{
		vector<TreeNode *> result;
		if (n == 0) {
			result.push_back(NULL);
			return result;
		}
		if (n == 1) {
			result.push_back(new TreeNode(beginValue));
			return result;
		}
		for (int i = 1; i <= n; ++ i)
		{
			// TreeNode *root = new TreeNode(i + beginValue - 1); // wrong !
			vector<TreeNode *> leftSubTrees = recursion(i-1, beginValue);
			vector<TreeNode *> rightSubTrees = recursion(n-i, beginValue + i);
			for (int j = 0; j < leftSubTrees.size(); ++ j) {
				for (int k = 0; k < rightSubTrees.size(); ++ k)
				{
					TreeNode *root = new TreeNode(i + beginValue - 1);
					root->left = leftSubTrees[j];
					root->right = rightSubTrees[k];
					result.push_back(root);
				}
			}
		}
		return result;
		
	}
	
    vector<TreeNode *> generateTrees(int n) 
	{
		vector<TreeNode *> result;
		if (n <= 0) {
			result.push_back(NULL);
			return result;
		}
        result = recursion(n, 1);
		return result;
    }
};