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
    ListNode *reverseBetween(ListNode *head, int m, int n) 
	{
		if (head == NULL)
			return head;
        ListNode *begin, *end, *p, *q;
		ListNode *pre = NULL, *last = NULL;
		begin = head;
        for (int i = 1; i < m; ++ i)
		{
			pre = begin;
			begin = begin->next;
		}
		end = begin;
		for (int i = m; i < n; ++ i)
		{
			end = end->next;
		}
		last = end->next;
		p = begin->next;
		q = begin;
		for (int i = m; i < n; ++ i)
		{
			if (p == NULL) // error
				return head;
			ListNode *l = p->next;
			p->next = q;
			q = p;
			p = l;
		}
		if (pre != NULL) {
			pre->next = q;
			begin->next = last;
			return head;
		} else {
			begin->next = last;
			return end;
		}
		
    }
};