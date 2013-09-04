/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int maxHeight(TreeNode *root)
	{
		if (root == NULL)
			return 0;
		int left = maxHeight(root->left) + 1;
		int right = maxHeight(root->right) + 1;
		return left > right ? left : right;
	}
	
    bool isBalanced(TreeNode *root) 
	{
        if (root == NULL)
			return true;
		int left = maxHeight(root->left);
		int right = maxHeight(root->right);
		if (abs(left - right) > 1)
			return false;
		return isBalanced(root->left) && isBalanced(root->right);
        
    }
};

/**
public static int checkHeight(TreeNode root) {
2 if (root == null) {
3 return 0; // Height of 0
4 }
5
6 /* Check if left is balanced. 
int leftHeight = checkHeight(root.left);
8 if (leftHeight == -1) {
9 return -1; // Not balanced
10 }
11 // Check if right is balanced. 
12 int rightHeight = checkHeight(root.right);
13 if (rightHeight == -1) {
14 return -1; // Not balanced
15 }
16
17 // Check if current node is balanced. 
18 int heightDiff = leftHeight - rightHeight;
19 if (Math.abs(heightDiff) > 1) {
20 return -1; // Not balanced
21 } else {
22 /* Return height 
23 return Math.max(leftHeightJ rightHeight) + 1;
24 }
25 }
26
27 public static boolean isBalanced(TreeNode root) {
28 if (checkHeight(root) == -1) {
29 return false;
30 } else {
31 return true;
32 }
33 }
This code runs in 0(N) time and 0(H) space, where H is the height of the tree.

**/