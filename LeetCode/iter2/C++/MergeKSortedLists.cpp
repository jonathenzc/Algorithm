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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0)
			return NULL;


		while(lists.size() > 1)
		{
			ListNode *list1 = lists.back();
			lists.pop_back();
			ListNode *list2 = lists.back();
			lists.pop_back();


			ListNode *mergedList = mergeTwoList(list1,list2);
			lists.push_back(mergedList);
		}

		return lists.back();
	}
private:
	ListNode *mergeTwoList(ListNode *l1, ListNode *l2)
	{
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;

		ListNode *head = NULL;
		if (l1->val < l2->val) {
			head = l1;
			l1 = l1->next;
		}
		else {
			head = l2;
			l2 = l2->next;
		}

		ListNode *traverse = head;

		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val < l2->val)
			{
				traverse->next = l1;
				l1 = l1->next;
			}
			else {
				traverse->next = l2;
				l2 = l2->next;
			}

			traverse = traverse->next;
		}

		if (l2 == NULL)
			traverse->next = l1;
		else
			traverse->next = l2;

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
	ListNode *l11 = new ListNode(4);
	ListNode *l12 = new ListNode(5);
	ListNode *l13 = new ListNode(6);
	ListNode *l14 = new ListNode(7);

	ListNode *l25 = new ListNode(8);
	ListNode *l26 = new ListNode(9);
	ListNode *l27 = new ListNode(1);
	ListNode *l28 = new ListNode(2);

	vector<ListNode*> v;
	v.push_back(l11);
	v.push_back(l12);
	v.push_back(l13);
	v.push_back(l14);
	v.push_back(l25);
	v.push_back(l26);
	v.push_back(l27);
	v.push_back(l28);

	Solution ss;
	ListNode *root = ss.mergeKLists(v);
	printList(root);

	return 0;
}