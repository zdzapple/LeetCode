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
    ListNode *rotateRight(ListNode *head, int k) 
	{
        if (k <= 0)
			return head;
		if (head == NULL)
			return head;
		int n = 0;
		ListNode *p = head;
		ListNode *q, *end;
		while (p != NULL)
		{
			p = p->next;
			n ++;
		}
        k = k % n; // important!!!
		if (k == 0)
			return head;
		p = head;
		for (int i = 0; i < n-k; ++ i) {
			q = p;
			p = p->next;
		}
		end = q;
		for (int i = 0; i < k; ++ i)
			end = end->next;
		// rotate
		end->next = head;
		q->next = NULL;
		return p;
    }
};
/*
	better:
首先从head开始跑，直到最后一个节点，这时可以得出链表长度len。然后将尾指针指向头指针，将整个圈连起来，接着往前跑len – k%len，从这里断开，就是要求的结果了。
*/