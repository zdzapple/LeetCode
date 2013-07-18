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
    int maxDepth(TreeNode *root) 
	{
        if (root == NULL)
			return 0;
		queue<TreeNode *> q;
		q.push(root);
		int levelNum = 0;
		int lastLevelNum = 1;
		int depth = 1;
		while (true)
		{
			while (lastLevelNum > 0)
			{
				TreeNode *r = q.front();
				q.pop();
				lastLevelNum --;
				if (r->left != NULL) {
					q.push(r->left);
					levelNum ++;
				}
				if (r->right != NULL) {
					q.push(r->right);
					levelNum ++;
				}
			}
			if (levelNum == 0)
				return depth;
			depth ++;
			lastLevelNum = levelNum;
			levelNum = 0;
			
		}
        return depth;
        
    }
};