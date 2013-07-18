/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //http://leetcode.com/2010/11/convert-sorted-list-to-balanced-binary.html
class Solution {
public:
	TreeNode *sortedListToBST(ListNode *list, int count)
	{
		if (count <= 0)
			return NULL;
		ListNode *rootListNode = list;
		int middle = count / 2;
		for (int i = 0; i < middle; ++ i)
			rootListNode = rootListNode->next;
		TreeNode *root = new TreeNode(rootListNode->val);
		root->left = sortedListToBST(list, middle);
		root->right = sortedListToBST(rootListNode->next, count - middle - 1);
		return root;			
	}
	
    TreeNode *sortedListToBST(ListNode *head) 
	{
		int count = 0;
		ListNode *begin = head;
		for (; begin != NULL; begin = begin->next)
			++ count;
		return sortedListToBST(head, count);
        
    }
};