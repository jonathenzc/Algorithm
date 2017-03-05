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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode *startNode = new ListNode(1);
		startNode->next = head;

		ListNode *nextNode = head;
		ListNode *preNextNode = startNode;
		while (nextNode != NULL)
		{
			ListNode *traverseNode = startNode->next;
			ListNode *preNode = startNode;
			bool changed = false;
			while (traverseNode != nextNode)
			{
				if (traverseNode->val <= nextNode->val)
				{
					preNode = traverseNode;
					traverseNode = traverseNode->next;
				}
				else
				{
					preNextNode->next = nextNode->next;
					nextNode->next = traverseNode;
					preNode->next = nextNode;

					changed = true;
					break;
				}
			}

			if (changed)
			{
				nextNode = preNextNode->next;
			}
			else
			{
				preNextNode = nextNode;
				nextNode = nextNode->next;
			}
		}

		return startNode->next;
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
	ListNode *l1 = new ListNode(6);
	ListNode *l2 = new ListNode(5);
	ListNode *l3 = new ListNode(4);
	ListNode *l4 = new ListNode(3);
	ListNode *l5 = new ListNode(2);
	ListNode *l6 = new ListNode(1);

	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = l6;

	Solution ss;
	ListNode *root = ss.insertionSortList(l1);
	printList(root);

	return 0;
}