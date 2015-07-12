#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverse(ListNode *head) {
	ListNode *prev = nullptr;
	while (head != nullptr) {
		ListNode *next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	return prev;
}


//时间复杂度O(n), 空间复杂度O(1)
//bool isPalindrome(ListNode* head) 
//{
//	bool result = true;
//	if (head!=NULL)
//	{
//		//获取链表的中间节点,借助另一个指针每次走两个节点来保证mid指向的是链表的中间节点
//		ListNode *quickNode = head;
//		ListNode *mid = head;
//		while (quickNode != NULL && quickNode->next != NULL)
//		{
//			mid = mid->next;
//			quickNode = quickNode->next->next;
//		}
//
//		////将mid之后到尾节点的链表都翻转
//		//ListNode *tail = mid;//最终将指向链表最后的节点
//		//ListNode *preNode = tail;
//		//ListNode *nextNode = tail->next;
//
//		//while (nextNode!=NULL)
//		//{
//		//	tail = nextNode;
//		//	nextNode = nextNode->next;
//		//	tail->next = preNode;
//		//	preNode = tail;
//		//}
//
//		ListNode *tail = reverse(mid);
//
//		//比较两个长度为size/2的链表
//		while (head != mid)
//		{
//			if (head->val != tail->val)
//			{
//				result = false;
//				break;
//			}
//
//			head = head->next;
//			tail = tail->next;
//		}
//	}
//
//	return result;
//}


bool isPalindrome(ListNode* head)
{
	bool result = true;
	if (head != NULL)
	{
		//获取链表长度
		int size = 0;
		ListNode *temp = head;
		for (temp; temp != NULL; temp = temp->next, size++);

		//访问到size/2个节点，并翻转
		ListNode *halfHead = head;//指向链表中间的节点
		ListNode *preNode = halfHead;
		ListNode *nextHalfHead = halfHead->next;

		for (int i = 0; i < size / 2 - 1; i++)
		{
			halfHead = nextHalfHead;
			nextHalfHead = nextHalfHead->next;
			halfHead->next = preNode;
			preNode = halfHead;
		}

		//比较两个长度为size/2的链表
		if (nextHalfHead != NULL && size & 1 == 1)//奇数需要将nextHalfHead指向下一个节点
			nextHalfHead = nextHalfHead->next;

		while (nextHalfHead != NULL)
		{
			if (halfHead->val != nextHalfHead->val)
				return false;

			halfHead = halfHead->next;
			nextHalfHead = nextHalfHead->next;
		}
	}

	return result;
}

int main()
{
	ListNode *node = new ListNode(1);
	ListNode *head = node;

	for (int i = 2; i <= 4; i++)
	{
		ListNode *temp = new ListNode(i);
		node->next = temp;
		node = node->next;
	}

	for (int i = 4; i > 0; i--)
	{
		ListNode *temp = new ListNode(i);
		node->next = temp;
		node = node->next;
	}

	//while (head != NULL)
	//{
	//	cout << head->val << " ";
	//	head = head->next;
	//}

	if (isPalindrome(head))
		cout << "Yes";
	else
		cout << "No";
	

	return 0;
}