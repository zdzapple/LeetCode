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
	void inOderTraversal(TreeNode *root, vector<int> &value, vector<TreeNode *> &node)
	{
		if (root == NULL)
			return;
		inOderTraversal(root->left, value, node);
		value.push_back(root->val);
		node.push_back(root);
		inOderTraversal(root->right, value, node);
	}
	
    void recoverTree1(TreeNode *root)  // O(n) version
	{
        vector<int> value;
		vector<TreeNode *> node;
		if (root == NULL)
			return;
		inOderTraversal(root, value, node);
		sort(value.begin(), value.end());
		// reassign the value
		for (int i = 0; i < value.size(); ++ i)
			node[i]->val = value[i];
    }
	
	void inOder(TreeNode *root, TreeNode * &pre, TreeNode * &p, TreeNode * &q) 
	{
         if (!root) return;
         inOder(root->left, pre, p, q);
         if (pre && pre->val > root->val) {
             if (!p) p = pre;
             q = root;
         }
         pre = root;
         inOder(root->right, pre, p, q);
     }
	
	void recoverTree(TreeNode *root) // O(1) version
	// while inOderTraversing the tree, it is like the way we sort and find the 2 wrong index.
	// so we only need to find the wrong index when we inOderTraverse the tree.
	{
		 TreeNode *p, *q, *pre;
         pre = p = q = NULL;
         inOder(root, pre, p, q);
         int tmp = p->val;
         p->val = q->val;
         q->val = tmp;
	}
};