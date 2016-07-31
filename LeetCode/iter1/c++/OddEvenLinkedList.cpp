#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


//ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(n)
//ListNode* oddEvenList(ListNode* head) {
//	if (head == NULL || head->next == NULL) //�����ڵ���߿սڵ�	
//		return head;
//
//	ListNode *oddList = new ListNode(head->val);
//	ListNode *oddTraverse = oddList;
//
//	head = head->next;
//	ListNode *evenList = new ListNode(head->val);
//	ListNode *evenTraverse = evenList;
//
//	head = head->next;
//
//	int cnt = 3; //��3���ڵ�
//
//	while (head != NULL)
//	{
//		ListNode *temp = new ListNode(head->val);
//
//		if (cnt % 2 == 1) //����
//		{
//			oddTraverse->next = temp;
//			oddTraverse = temp;
//		}
//		else
//		{
//			evenTraverse->next = temp;
//			evenTraverse = temp;
//		}
//
//		cnt++;
//		head = head->next;
//	}
//
//	oddTraverse->next = evenList; //�����е�β��ָ��ż���е�ͷ
//
//	return oddList;
//}


ListNode* oddEvenList(ListNode* head) {
	if (head == NULL || head->next == NULL) //�����ڵ�
		return head;

	ListNode *oddTraverse = head;
	ListNode *even_head = head->next;
	ListNode *evenTraverse = head->next;

	while (evenTraverse != NULL && evenTraverse->next != NULL)
	{
		oddTraverse->next = evenTraverse->next;
		evenTraverse->next = evenTraverse->next->next;

		oddTraverse = oddTraverse->next;
		evenTraverse = evenTraverse->next;
	}

	//�����е�β��ָ��ż���е�ͷ
	oddTraverse->next = even_head;

	return head;
}

ListNode *initiateList(int n)
{
	ListNode *list = new ListNode(1);
	ListNode *traverse = list;
	for (int i = 2; i <= n; i++)
	{
		ListNode *tmp = new ListNode(i);
		traverse->next = tmp;
		traverse = tmp;
	}

	return list;
}

void outputList(ListNode *node)
{
	while (node != NULL)
	{
		cout << node->val << " ";
		node = node->next;
	}

	cout << endl;
}

int main()
{
	ListNode *list = initiateList(7);
	outputList(list);

	ListNode *resultList = oddEvenList(list);

	outputList(resultList);



	return 0;
} 