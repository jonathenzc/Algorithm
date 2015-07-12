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


//ʱ�临�Ӷ�O(n), �ռ临�Ӷ�O(1)
//bool isPalindrome(ListNode* head) 
//{
//	bool result = true;
//	if (head!=NULL)
//	{
//		//��ȡ������м�ڵ�,������һ��ָ��ÿ���������ڵ�����֤midָ�����������м�ڵ�
//		ListNode *quickNode = head;
//		ListNode *mid = head;
//		while (quickNode != NULL && quickNode->next != NULL)
//		{
//			mid = mid->next;
//			quickNode = quickNode->next->next;
//		}
//
//		////��mid֮��β�ڵ��������ת
//		//ListNode *tail = mid;//���ս�ָ���������Ľڵ�
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
//		//�Ƚ���������Ϊsize/2������
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
		//��ȡ������
		int size = 0;
		ListNode *temp = head;
		for (temp; temp != NULL; temp = temp->next, size++);

		//���ʵ�size/2���ڵ㣬����ת
		ListNode *halfHead = head;//ָ�������м�Ľڵ�
		ListNode *preNode = halfHead;
		ListNode *nextHalfHead = halfHead->next;

		for (int i = 0; i < size / 2 - 1; i++)
		{
			halfHead = nextHalfHead;
			nextHalfHead = nextHalfHead->next;
			halfHead->next = preNode;
			preNode = halfHead;
		}

		//�Ƚ���������Ϊsize/2������
		if (nextHalfHead != NULL && size & 1 == 1)//������Ҫ��nextHalfHeadָ����һ���ڵ�
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