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
		p = head;
		q = new ListNode(-1);
		q->next = head;
		ListNode *result = q;
		bool isDuplicate = false;
		while (p != NULL)
		{
			isDuplicate = false;
			ListNode *next = p->next;
			while (next != NULL && next->val == p->val) 
			{
				p->next = next->next;
				next->next = NULL;
				delete next;
				next = p->next;
				isDuplicate = true;
			}
			// delete p
			if (isDuplicate) {
				q->next = next;
				p->next = NULL;
				delete p;
				p = next;
			} else {
				p = p->next;
				q = q->next;
			}			
		}
        return result->next;
    }
};