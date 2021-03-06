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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) 
	{
		vector<vector<int> > result;
		if (root == NULL)
			return result;
		int currentLevel = 0;
		int previousLevel = 0;
		bool traverse = false;
		queue<TreeNode *> nodesQueue;
		nodesQueue.push(root);
		previousLevel ++;
		vector<int> level;
		while (!nodesQueue.empty())
		{
			level.clear();
			while (previousLevel > 0)
			{
				TreeNode *current = nodesQueue.front();
				nodesQueue.pop();
				previousLevel --;
				level.push_back(current->val);
				if (current->left != NULL) {
					currentLevel ++;
					nodesQueue.push(current->left);
				}
				if (current->right != NULL) {
					currentLevel ++;
					nodesQueue.push(current->right);
				}
			}
			if (!level.empty()) {
				if (!traverse)
					result.push_back(level);
				else {
					reverse(level.begin(), level.end());
					result.push_back(level);
				}
				traverse = !traverse;
			}
			previousLevel = currentLevel;
			currentLevel = 0;
		}
		return result;
    }
};