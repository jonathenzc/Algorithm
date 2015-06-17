#include <iostream>

using namespace std;

struct listNode
{
	int val;
	listNode *next;
	listNode(int theVal){ val = theVal; next = NULL; }
};

////空间复杂度O(n)
//listNode *reverseList(listNode *head)
//{
//	listNode *reversedList = NULL;
//
//	if (head != NULL)
//	{
//		reversedList = new listNode(head->val);
//		head = head->next;
//		while (head != NULL)
//		{
//			listNode *temp = new listNode(head->val);
//			temp->next = reversedList;
//			reversedList = temp;
//
//			head = head->next;
//		}
//	}
//
//	return reversedList;
//}

//空间复杂度O(1)
listNode *reverseList(listNode *head)
{
	listNode *reversedHead = NULL;

 	if (head != NULL)
	{
		reversedHead = head;//如果只有一个节点，就会直接返回head节点
		listNode *reversedIter = head->next;
		head->next = NULL;

		while (reversedIter != NULL)
		{
			reversedHead = reversedIter;
			reversedIter = reversedIter->next;

			reversedHead->next = head;
			head = reversedHead;
		}
	}

	return reversedHead;
}

void outputList(listNode *head)
{
	while (head != NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;
}

int main()
{
	listNode *head = new listNode(1);
	listNode *node2 = new listNode(2);
	listNode *node3 = new listNode(3);
	listNode *node4 = new listNode(4);
	listNode *node5 = new listNode(5);

	head->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	
	outputList(head);

	head = reverseList(head);

	outputList(head);


	return 0;
}