/**
链表结点的定义(请不要在代码中定义该类型)
struct ListNode {
    ListNode *next;
    ListNode *random;
};
*/
// 返回复制的新链表头结点
ListNode* copyListWithRandomPtr(ListNode *head) 
{
	if (head == NULL)
		return NULL;
	ListNode *ptr = head;
	while (ptr != NULL)
	{
		ListNode *duplicate = new ListNode();
		duplicate->next = ptr->next;
		duplicate->random = NULL;
		ptr->next = duplicate;
		ptr = ptr->next->next;
	}
	ptr = head;
	// copy random pointer
	while (ptr != NULL)
	{
		if (ptr->random != NULL)
			ptr->next->random = ptr->random->next;
		ptr = ptr->next->next;
	}
	ptr = head;
	ListNode *result = ptr->next;
	ListNode *duplicate = ptr->next;
	// 把copy random pointer和恢复原表分开做
	while (ptr != NULL)
	{
		ptr->next = duplicate->next;
		ptr = ptr->next;
		if (ptr != NULL) {
			duplicate->next = ptr->next;
			duplicate = duplicate->next;
		}
	}
	return result;
}