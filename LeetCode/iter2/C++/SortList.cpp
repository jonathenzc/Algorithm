#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (head == NULL)
			return NULL;

		return mergeSort(head);
	}
private:
	ListNode *mergeSort(ListNode *head)
	{
		if (head == NULL || head->next == NULL)
			return head;

		ListNode *slow = head;
		ListNode *fast = head;
		ListNode *preSlow = head;

		while (fast != NULL && fast->next != NULL)
		{
			preSlow = slow;
			slow = slow->next;
			fast = fast->next->next;
		}

		preSlow->next = NULL;

		ListNode *listHead1 = mergeSort(head);
		ListNode *listHead2 = mergeSort(slow);

		return mergeTwoList(listHead1, listHead2);
	}

	ListNode *mergeTwoList(ListNode *list1, ListNode *list2)
	{
		if (list1 == NULL)
			return list2;

		if (list2 == NULL)
			return list1;

		ListNode *head = NULL;
		if (list1->val > list2->val) {
			head = list2;
			list2 = list2->next;
		}
		else{
			head = list1;
			list1 = list1->next;
		}

		ListNode *traverseNode = head;

		ListNode *pre1 = list1;
		ListNode *next2 = list2;
		while (list1 != NULL && list2 != NULL)
		{
			if (list1->val < list2->val)
			{
				traverseNode->next = list1;
				list1 = list1->next;
			}
			else
			{
				traverseNode->next = list2;
				list2 = list2->next;
			}

			traverseNode = traverseNode->next;
		}

		if(list2 != NULL)
			traverseNode->next = list2;
		
		if (list1 != NULL)
			traverseNode->next = list1;


		return head;
	}
};

void printList(ListNode *l)
{
	while (l != NULL)
	{
		cout << l->val << " ";
		l = l->next;
	}

	cout << endl;
}

int main(void)
{
	ListNode *l1 = new ListNode(3);
	ListNode *l2 = new ListNode(2);
	ListNode *l3 = new ListNode(4);
	ListNode *l4 = new ListNode(3);
	ListNode *l5 = new ListNode(2);
	ListNode *l6 = new ListNode(1);

	l1->next = l2;
	l2->next = l3;
	//l3->next = l4;
	//l4->next = l5;
	//l5->next = l6;

	Solution ss;
	ListNode *root = ss.sortList(l1);
	printList(root);

	return 0;
}