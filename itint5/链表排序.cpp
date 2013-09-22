#include <climits>
ListNode* merge(ListNode *head1, int len1, ListNode *head2, int len2)
{
	if (len1 <= 0)
		return head2;
	if (len2 <= 0)
		return head1;
	ListNode *result = new ListNode();
	ListNode *p = result;
	ListNode *NULLNODE = new ListNode();
	NULLNODE->val = INT_MAX;
	int len = len1 + len2;
	for (int k = 0; k < len; ++ k)
	{
		ListNode* first;
		ListNode *second;
		first = head1 == NULL ? NULLNODE : head1;
		second = head2 == NULL ? NULLNODE : head2;

		if (first->val <= second->val) {
			result->next = first;
			len1 --;
			if (len1 <= 0)
				head1 = NULL;
			else
				head1 = head1->next;
		} else {
			result->next = second;
			len2 --;
			if (len2 <= 0)
				head2 = NULL;
			else
				head2 = head2->next;
		}
		result = result->next;
	}
	result->next = NULL; // 要不就有环了
	result = p->next;
	delete p;
	return result;

}

ListNode* mergeSort(ListNode *head, int len)
{
	if (len == 1)
		return head;
	int r = len / 2;

	ListNode *p = head;
	while (r > 0)
	{
		r --;
		p = p->next;
	}
	ListNode *first = mergeSort(head, len / 2);
	ListNode *second = mergeSort(p, len - len / 2);
	return merge(first, len / 2, second, len - len / 2);
}

ListNode* sortLinkList(ListNode *head)
{
	if (head == NULL)
		return head;
	int len = 0;
	ListNode *p = head;
	while (p != NULL)
	{
		p = p->next;
		len ++;
	}

	return mergeSort(head, len);
}