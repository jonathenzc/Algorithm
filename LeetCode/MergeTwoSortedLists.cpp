#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
	if (l1 == NULL && l2 == NULL)
		return NULL;
	else if (l1 == NULL)
		return l2;
	else if (l2 == NULL)
		return l1;
	else
	{
		ListNode *mergedList = NULL;
		ListNode *mergedListRoot = NULL;

		while (l1 != NULL && l2 != NULL)
		{
			ListNode * temp;
			if (l1->val < l2->val)
				temp = new ListNode(l1->val);
			else
				temp = new ListNode(l2->val);

			if (mergedList == NULL)//还未插入节点
			{
				mergedList = temp;
				mergedListRoot = mergedList;
			}
			else
			{
				mergedList->next = temp;
				mergedList = mergedList->next;
			}

			if (l1->val < l2->val)
				l1 = l1->next;
			else
				l2 = l2->next;
		}

		if (l1 != NULL)
			mergedList->next = l1;

		if (l2 != NULL)
			mergedList->next = l2;

		return mergedListRoot;
	}
}

int main()
{
	return 0;
}