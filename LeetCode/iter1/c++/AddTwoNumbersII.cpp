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
		int len1 = listLen(l1);
		int len2 = listLen(l2);

		//调整成l1比l2长
		if (len2 > len1)
		{
			ListNode *tmp = l2;
			l2 = l1;
			l1 = tmp;
		}

		//补全l2
		int diff = abs(len1 - len2);
		if (diff > 0) {
			ListNode *tmpHead = new ListNode(0);
			ListNode *traverse = tmpHead;
			while (diff > 1)
			{
				ListNode *tmp = new ListNode(0);
				traverse->next = tmp;
				traverse = traverse->next;
				diff--;
			}

			traverse->next = l2;
			l2 = tmpHead;
		}

		//加l1和l2
		int addDigit = helper(l1,l2);
		if (addDigit == 1)
		{
			ListNode *newHead = new ListNode(1);
			newHead->next = l1;
			l1 = newHead;
		}

		return l1;
	}
private:
	int listLen(ListNode *l)
	{
		int cnt = 0;

		while (l != NULL)
		{
			cnt++;
			l = l->next;
		}
		
		return cnt;
	}

	int helper(ListNode *l1, ListNode *l2)
	{
		if (l2 == NULL)
			return 0;

		int addNumber = helper(l1->next,l2->next);
		int sum = addNumber + l1->val + l2->val;
		int ret = 0;
		if (sum > 9) {
			ret = 1;
			sum -= 10;
		}

		l1->val = sum;

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
	ListNode *l11 = new ListNode(4);
	ListNode *l12 = new ListNode(5);
	ListNode *l13 = new ListNode(6);
	ListNode *l14 = new ListNode(7);

	l11->next = l12;
	l12->next = l13;
	l13->next = l14;

	ListNode *l25 = new ListNode(8);
	ListNode *l26 = new ListNode(9);
	ListNode *l27 = new ListNode(1);
	ListNode *l28 = new ListNode(2);

	l25->next = l26;
	l26->next = l27;
	l27->next = l28;

	Solution ss;
	ListNode *root = ss.addTwoNumbers(l11, l25);
	printList(root);

	return 0;
}