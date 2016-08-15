#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	/** @param head The linked list's head.
	Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode* head) {
		while (head != NULL)
		{
			v.push_back(head->val);
			head = head->next;
		}
	}

	/** Returns a random node's value. */
	int getRandom() {
		return v[rand() % v.size()];
	}
private:
	vector<int> v;
};


int main()
{


	return 0;
}