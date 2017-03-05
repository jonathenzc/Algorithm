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
	TreeNode* sortedListToBST(ListNode* head) {
		if (head == NULL)
			return NULL;

		if (head->next == NULL)
			return new TreeNode(head->val);

		ListNode *slow = head;
		ListNode *fast = head;
		ListNode *preNode = head;
		while (fast != NULL && fast->next != NULL)
		{
			preNode = slow;
			slow = slow->next;
			fast = fast->next->next;
		}

		preNode->next = NULL;

		TreeNode *root = new TreeNode(slow->val);
		root->left = sortedListToBST(head);
		root->right = sortedListToBST(slow->next);

		return root;
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

void printTree(TreeNode *root)
{
	if (root != NULL)
	{
		printTree(root->left);
		cout << root->val << " ";
		printTree(root->right);
	}
}

int main(void)
{
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(2);
	ListNode *l3 = new ListNode(3);
	ListNode *l4 = new ListNode(4);
	ListNode *l5 = new ListNode(5);
	ListNode *l6 = new ListNode(6);

	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	//l5->next = l6;

	Solution ss;
	TreeNode *root = ss.sortedListToBST(l1);
	printTree(root);

	return 0;
}