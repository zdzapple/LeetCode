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
    ListNode *swapTwoNode(ListNode *pre, ListNode *first, ListNode *second)
	// note: don't forget the preNode
	{
		ListNode *third = second->next;
		second->next = first;
		first->next = third;
        if (pre != NULL)
            pre->next = second;
		return second;
	}
	
    ListNode *swapPairs(ListNode *head) 
	{
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *result = swapTwoNode(NULL, head, head->next);
		head = result->next->next;
        ListNode *pre = result->next;
		while (head != NULL && head->next != NULL)
		{
			ListNode *temp = swapTwoNode(pre, head, head->next);
			head = temp->next->next;
            pre = temp->next;
		}
		return result;
    }
};