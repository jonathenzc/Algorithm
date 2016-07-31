#include <iostream>
#include <vector>

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

ListNode *getMid(ListNode* start, ListNode *end)
{
	ListNode *slow = start;
	ListNode *fast = start;

	ListNode *result = start;

	while (slow != end && fast != end)
	{
		fast = fast->next;
		if (fast != end)
		{
			fast = fast->next;
			if (fast == end)
			{
				result = slow->next;
				break;
			}
		}
		else
		{
			result = slow;
			break;
		}

		slow = slow->next;
	}

	return result;
}

TreeNode* sortHelper(ListNode* start, ListNode *end)
{
	if (start == NULL || start == end)
		return NULL;

	if (start->next == NULL || start->next == end)
	{
		TreeNode *tmp = new TreeNode(start->val);
		return tmp;
	}

	//获取链表的中间节点
	ListNode* midNode = getMid(start,end);

	TreeNode *node = new TreeNode(midNode->val);

	node->left = sortHelper(start,midNode);
	node->right = sortHelper(midNode->next,end);

	return node;
}

TreeNode* sortedListToBST(ListNode* head) {
	TreeNode *result = sortHelper(head,NULL);

	return result;
}

int main()
{
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);
	ListNode* node5 = new ListNode(5);
	ListNode* node6 = new ListNode(6);
	ListNode* node7 = new ListNode(7);
	ListNode* node8 = new ListNode(8);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = node7;
	node7->next = node8;


	TreeNode* result = sortedListToBST(node1);

	cout <<"Finished" <<endl;

	return 0;
}
