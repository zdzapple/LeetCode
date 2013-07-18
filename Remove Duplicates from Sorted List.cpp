/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode *deleteDuplicates(ListNode *head) 
	{
        if (head == NULL)
			return head;
		ListNode *p, *q;
		p = head->next;
		q = head;
		while (p != NULL)
		{
			if (p->val == q->val) {
				ListNode *tmp = p->next;
				q->next = tmp;
				p->next = NULL;
				delete p;
				p = tmp;
			} else {
				p = p->next;
				q = q->next;
			}
		}
		return head;
        
    }
};