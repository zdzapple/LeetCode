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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) 
    {
		ListNode *p, *q;
		ListNode *result, *rp;
		p = l1, q = l2;
		result = NULL;
        
        /** important **/
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        
		while (p != NULL && q != NULL)
		{
			if (p->val < q->val) {
				copyToResult(result, rp, p);			
			} else {
				copyToResult(result, rp, q);
			}
		}
		if (p != NULL) {
			/*while (q != NULL) {
				copyToResult(result, rp, q);
				q = q->next;
			}*/
			rp->next = p;
		} else if (q != NULL) {
			rp->next = q;
		}
		return result;
        
    }
	
	/** note: &type, don't just use ListNode* result, instead use ListNode*& result **/
	void copyToResult(ListNode*& result, ListNode*& rp, ListNode*& p)
	{
		if (result == NULL) {
			result = p;
			rp = p;
		} else {
			rp->next = p;
			rp = p;
		}
        p = p->next;
        rp->next = NULL;
	}
};

/**

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) 
	{
        ListNode *result = new ListNode(-1);
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		ListNode *p = result;
		while (l1 != NULL || l2 != NULL)
		{
			int val1 = l1 == NULL ? INT_MAX : l1->val;
			int val2 = l2 == NULL ? INT_MAX : l2->val;
			if (val1 <= val2) {
				p->next = l1;
				l1 = l1->next;
			} else {
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
        p = result->next;
		delete result;
		return p;
    }
};
**/