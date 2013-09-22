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