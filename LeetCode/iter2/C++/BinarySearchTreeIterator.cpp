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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		InOrderHelper(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !q.empty();
	}

	/** @return the next smallest number */
	int next() {
		int val = q.front();
		q.pop();

		return val;
	}
private:
	queue<int> q;

	void InOrderHelper(TreeNode *root)
	{
		if (root != NULL)
		{
			InOrderHelper(root->left);
			q.push(root->val);
			InOrderHelper(root->right);
		}
	}
};

int main(void)
{
	TreeNode *root = new TreeNode(4);
	TreeNode *node1 = new TreeNode(2);
	TreeNode *node2 = new TreeNode(6);
	TreeNode *node3 = new TreeNode(1);
	TreeNode *node4 = new TreeNode(3);
	TreeNode *node5 = new TreeNode(5);
	TreeNode *node6 = new TreeNode(7);

	root->left = node1;
	root->right = node2;

	node1->left = node3;
	node1->right = node4;

	node2->left = node5;
	node2->right = node6;

	BSTIterator i = BSTIterator(root);
	while (i.hasNext()) 
		cout << i.next()<<" ";

	return 0;
}