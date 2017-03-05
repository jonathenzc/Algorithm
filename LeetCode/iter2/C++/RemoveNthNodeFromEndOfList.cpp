class Solution {
public:
	//通过快慢节点来定位将要被删除的节点位置
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *ret = new ListNode(0); //处理删除第一个节点时的情况
		ret->next = head;

		ListNode *slow = ret;
		ListNode *fast = head;

		for (int i = 0; i < n; i++)
			fast = fast->next;

		while (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}

		//slow的next即为从后数的第n个节点
		slow->next = slow->next->next;

		return ret->next;
	}
};