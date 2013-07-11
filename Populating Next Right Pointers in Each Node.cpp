/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) 
    {
		if (root == NULL)
			return;
		if (root->left == NULL && root->right == NULL)
			return;
		root->left->next = root->right;
		if (root->next != NULL) {
			TreeLinkNode* next = root->next;
			root->right->next = next->left;
		} else
			root->right->next = NULL;
        connect(root->left);
		connect(root->right);
    }
};