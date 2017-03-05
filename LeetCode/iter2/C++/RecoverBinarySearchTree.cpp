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

class Solution {
public:
	void recoverTree(TreeNode* root) {
		firstNode = NULL;
		secondNode = NULL;
		preNode = new TreeNode(INT_MIN);

		InOrderHelper(root);

		int tmp = firstNode->val;
		firstNode->val = secondNode->val;
		secondNode->val = tmp;
	}
private:
	TreeNode *firstNode;
	TreeNode *secondNode;
	TreeNode *preNode;

	void InOrderHelper(TreeNode *root)
	{
		if (root != NULL)
		{
			InOrderHelper(root->left);

			if (firstNode == NULL && preNode != NULL && preNode->val >= root->val)
				firstNode = preNode;

			if (firstNode != NULL && preNode != NULL && preNode->val >= root->val)
				secondNode = root;

			preNode = root;

			InOrderHelper(root->right);
		}
	}
};

void InOrderPrint(TreeNode *root)
{
	if (root != NULL)
	{
		InOrderPrint(root->left);
		cout << root->val;
		InOrderPrint(root->right);
	}
}

int main(void)
{
	TreeNode *root = new TreeNode(0);
	TreeNode *node1 = new TreeNode(1);
	
	root->left = node1;

	cout << "Before\n";
	InOrderPrint(root);

	Solution s;
	s.recoverTree(root);

	cout << "\nAfter\n";
	InOrderPrint(root);

	cout << endl;

	return 0;
}