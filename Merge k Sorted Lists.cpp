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
// 100 milli secs
    ListNode *mergeKLists1(vector<ListNode *> &lists) 
	{ 
		ListNode *result, *pResult;
		if (lists.empty())
			return NULL;
		int n = lists.size();
		int i = 0;
		vector<ListNode *> pList;
		pList.reserve(n);
		result = new ListNode(-1);
		pResult = result;
		for (i = 0; i < n; ++ i)
		{
			ListNode *p = lists[i];
			pList.push_back(p);
		}
		int empty = 0;
		ListNode *s;
		int temp;
		while (empty < n)
		{
			s = new ListNode(INT_MAX);
			temp = -1;
			for (i = 0; i < n; ++ i)
			{
				ListNode *p = pList[i];
				if (p != NULL && p->val < s->val) {
					s->val = p->val;
					temp = i;
				}
			}
			if (temp != -1) { // note: [{}]
				pResult->next = s;
				pResult = pResult->next;
				pList[temp] = pList[temp]->next;
				if (pList[temp] == NULL)
					empty ++;
			} else
				break;			
			
		}
		return result->next;
    }
	
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
	
	/** note: &type, don't just use ListNode* result, use ListNode*& result instead**/
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
	//68 milli secs
	ListNode *mergeKLists(vector<ListNode *> &lists) 
	{ 
		ListNode *result, *pResult;
		if (lists.empty())
			return NULL;
		int currentSize = lists.size();
		while (currentSize > 1)
		{
			int half = (currentSize + 1) >> 1;
			for (int i = 0; i < half && i + half < currentSize; ++ i)
			{
				ListNode *first = lists[i];
                ListNode *second = lists[i + half];
                ListNode *result = mergeTwoLists(first, second);
                lists[i] = result;
			}
			currentSize = half;
		}
		return lists[0];
	}
};