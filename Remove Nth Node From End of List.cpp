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
    ListNode *removeNthFromEnd(ListNode *head, int n) 
	{
        ListNode *begin = head;
		ListNode *end = head;
		int count = 0;
		while (count < n && end != NULL)
		{
			end = end->next;
			count ++;
		}
		if (count == n && end == NULL) {
			// remove the first node
			head = head->next;
			delete begin;
			return head;
		}
		while (end->next != NULL)
		{
			begin = begin->next;
			end = end->next;
		}
		ListNode *toRemove = begin->next;
		begin->next = toRemove->next;
		delete toRemove;
		return head;
    }
};