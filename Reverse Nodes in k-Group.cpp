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
	// reverse linked list from begin to end. 
	// p is the next node of the last node of the linked list
	ListNode *reverse(ListNode *begin, ListNode* end, ListNode *p)
	{
		ListNode *b = begin;
		b = b->next;
		ListNode *a = begin;
		while (a != end)
		{
			ListNode *temp = b->next;
			b->next = a;
			a = b;
			b = temp;
		}
		begin->next = p;
		return a; // the last node 
	}
	
    ListNode *reverseKGroup(ListNode *head, int k) 
	{
        ListNode *result = NULL;
		if (k <= 1)
			return head;
		int count = 0;
		result = new ListNode(-1);
		result->next = head;
		ListNode *p = head;
		ListNode *q = p;
		ListNode *begin = result;
		while (true)
		{
			count = 0;
			while (count < k && p != NULL)
			{
				q = p;
				p = p->next;
				count ++;
			}
			if (p == NULL) {
				if (count < k)
					break;
			}
			ListNode *beginNode = begin->next;
			begin->next = reverse(beginNode, q, p);
			begin = beginNode;
		}
		return result->next;
        
    }
};