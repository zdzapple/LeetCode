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
    ListNode *addTwoNumbers1(ListNode *l1, ListNode *l2) 
	{
		if (l1 == NULL && l2 == NULL) {
			return NULL;
		}
		ListNode *result, *p, *temp;
		ListNode *leftNodes;
		int carry = 0;
		result = new ListNode(0);
		p = result;
		while (l1 != NULL && l2 != NULL)
		{
			int val = l1->val + l2->val + carry;
			carry = val / 10;
			val = val % 10;
			temp = new ListNode(val);
			p->next = temp;
			p = temp;
			
			l1 = l1->next;
			l2 = l2->next;
		}
		
		if (l1 != NULL)
			leftNodes = l1;
		else
			leftNodes = l2;
		while (leftNodes != NULL)
		{
			int val = leftNodes->val + carry;
			carry = val / 10;
			val %= 10;
			
			temp = new ListNode(val);
			p->next = temp;
			p = temp;
			
			leftNodes = leftNodes->next;
		}
		if (carry != 0)
			p->next = new ListNode(carry);

		return result->next;
    }
	// Simper
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
	{
		if (l1 == NULL && l2 == NULL) {
			return NULL;
		}
		ListNode *result, *p, *temp;
		ListNode *leftNodes;
		int carry = 0;
		result = new ListNode(0);
		p = result;
		while (l1 != NULL || l2 != NULL)
		{
			int a = (l1 == NULL) ? 0 : l1->val;
			int b = (l2 == NULL) ? 0 : l2->val;
			int val = a + b + carry;
			carry = val / 10;
			val = val % 10;
			temp = new ListNode(val);
			p->next = temp;
			p = temp;
			
			l1 = (l1 == NULL ? NULL : l1->next);
			l2 = (l2 == NULL ? NULL : l2->next);
		}
		
		if (carry != 0)
			p->next = new ListNode(carry);

		return result->next;
    }
	
};