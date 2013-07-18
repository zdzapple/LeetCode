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
/**
	为了保证head不为空，可以在头部添加一个值为x-1的哑指针，最后再删掉
**/
	ListNode *partition(ListNode *head, int x)
	{
		if (head == NULL)
			return head;
		ListNode *result = new ListNode(x-1);
		result->next = head;
		ListNode *p, *q, *tmp, *k;
		p = head;
		q = result; // q is the last node that less than x
		k = NULL; // k is the last node that no less than x
		while (p != NULL)
		{
			if (p->val < x) {
				tmp = p->next;
				if (k != NULL) {
					k->next = tmp;
					p->next = q->next; // if p == q->next, then we get endless loop
				} else {
					
				}
				q->next = p;
				q = p;
				p = tmp;
			} else {
				k = p;
				p = p->next;
			}
		}
		return result->next;
	}
	
    ListNode *partition1(ListNode *head, int x) 
	{
        if (head == NULL)
			return head;
		ListNode *p, *q, *tmp, *k;
		ListNode *result = head;
		p = head;
		q = NULL; // q is the last node that less than x
		k = NULL; // k is the last node that no less than x
		while (p != NULL)
		{
			if (p->val < x) {
				tmp = p->next;
				if (q == NULL) { // first node
					q = p;
					if (k != NULL)
						k->next = tmp;
					if (q != head)
						q->next = head;
					p = tmp;
					result = q;
				} else {
					if (k != NULL) {
						k->next = tmp;
						p->next = q->next;
					} else {
						
					}
					q->next = p;
					q = p;
					p = tmp;
				}				
			} else {
				k = p;
				p = p->next;
			}
		}
		return result;
    }
};