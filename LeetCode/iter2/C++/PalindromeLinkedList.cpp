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
	//利用快慢指针，使得慢指针停在中间，然后开始翻转指针比较
	bool isPalindrome(ListNode* head) {
		ListNode *slow = head;
		ListNode *fast = head;

		while (fast != NULL && fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		bool ret = true;
		ListNode *reversedNode = reverseList(slow);
		while (head != NULL && reversedNode != NULL)
		{
			if (head->val != reversedNode->val)
			{
				ret = false;
				break;
			}

			head = head->next;
			reversedNode = reversedNode->next;
		}

		return ret;
	}

	ListNode* reverseList(ListNode* head) {
		if (head == NULL)
			return head;

		ListNode *nextNode = head->next;
		head->next = NULL;
		ListNode *nextNextNode = nextNode;
		while (nextNode != NULL) {
			nextNextNode = nextNode->next;
			nextNode->next = head;

			head = nextNode;
			nextNode = nextNextNode;
		}

		return head;
	}
};

int main(void)
{
	ListNode *l1 = new ListNode(2);
	ListNode *l2 = new ListNode(3);
	ListNode *l3 = new ListNode(3);
	ListNode *l4 = new ListNode(2);
	ListNode *l5 = new ListNode(1);

	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	//l4->next = l5;

	Solution ss;

	if (ss.isPalindrome(l1))
		cout << "Is palindrome\n";
	else
		cout << "Is not palindrome\n";
	

	return 0;
}