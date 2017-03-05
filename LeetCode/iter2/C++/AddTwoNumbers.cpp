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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* ret = NULL;
		ListNode* retNext = NULL;
		if (l1 == NULL)
			return l2;

		if (l2 == NULL)
			return l1;

		int bias = 0;
		while (l1 != NULL && l2 != NULL)
		{
			int sum = l1->val + l2->val+bias;
			if (sum > 9) {
				bias = 1;
				sum -= 10;
			}
			else
				bias = 0;

			if (ret == NULL) {
				ret = new ListNode(sum);
				retNext = ret;
			}
			else
			{
				ListNode *tmpNode = new ListNode(sum);
				retNext->next = tmpNode;
				retNext = retNext->next;
			}

			l1 = l1->next;
			l2 = l2->next;
		}

		if (l1 != NULL)
		{
			while (l1 != NULL)
			{
				int sum = l1->val + bias;
				if (sum > 9) {
					bias = 1;
					sum -= 10;
				}
				else
					bias = 0;

				ListNode *tmpNode = new ListNode(sum);
				retNext->next = tmpNode;
				retNext = retNext->next;

				l1 = l1->next;
			}

			if (bias == 1)
			{
				ListNode *tmpNode = new ListNode(bias);
				retNext->next = tmpNode;
				retNext = retNext->next;
			}
		}
		else if (l2 != NULL)
		{
			while (l2 != NULL)
			{
				int sum = l2->val + bias;
				if (sum > 9) {
					bias = 1;
					sum -= 10;
				}
				else
					bias = 0;

				ListNode *tmpNode = new ListNode(sum);
				retNext->next = tmpNode;
				retNext = retNext->next;

				l2 = l2->next;
			}

			if (bias == 1)
			{
				ListNode *tmpNode = new ListNode(bias);
				retNext->next = tmpNode;
				retNext = retNext->next;
			}
		}
		else //both NULL
		{
			if (bias == 1)
			{
				ListNode *tmpNode = new ListNode(bias);
				retNext->next = tmpNode;
				retNext = retNext->next;
			}
		}

		return ret;
	}
};

int main(void)
{
	ListNode *l11 = new ListNode(2);
	ListNode *l12 = new ListNode(4);
	ListNode *l13 = new ListNode(3);
	l11->next = l12;
	l12->next = l13;

	ListNode *l21 = new ListNode(5);
	ListNode *l22 = new ListNode(6);
	ListNode *l23 = new ListNode(4);
	l21->next = l22;
	l22->next = l23;

	Solution ss;

	ListNode *ret = ss.addTwoNumbers(l11,l21);

	while (ret != NULL)
	{
		cout << ret->val << " ";
		ret = ret->next;
	}

	return 0;
}