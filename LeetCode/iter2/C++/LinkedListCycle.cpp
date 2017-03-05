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
	bool hasCycle(ListNode *head) {
		bool ret = false;

		ListNode *fast = head;
		ListNode *slow = head;

		while (fast != NULL && fast->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;

			if (fast == slow)
			{
				ret = true;
				break;
			}
		}

		return ret;
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
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(1);
	ListNode *l3 = new ListNode(2);
	ListNode *l4 = new ListNode(2);
	ListNode *l5 = new ListNode(3);

	l1->next = l2;
	l2->next = l1;
	//l3->next = l4;
	//l4->next = l5;

	Solution ss;
	if (ss.hasCycle(l1))
		cout << "Yes\n";
	else
		cout << "No\n";
	

	return 0;
}