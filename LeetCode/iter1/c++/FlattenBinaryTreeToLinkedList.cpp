#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void flatten(TreeNode* root) 
{
	if (root == NULL)
		return;

	stack<TreeNode *> s;
	if (root->right != NULL)
		s.push(root->right);

	if (root->left != NULL)
		s.push(root->left);

	TreeNode *traverseNode = root;

	while (!s.empty())
	{
		TreeNode *topNode = s.top();
		s.pop();

		if (topNode->right != NULL)
			s.push(topNode->right);

		if (topNode->left != NULL)
			s.push(topNode->left);

		TreeNode *tmpNode = new TreeNode(topNode->val);

		traverseNode->left = NULL;
		traverseNode->right = tmpNode;

		traverseNode = tmpNode;
	}
}


int main()
{
	TreeNode *root = new TreeNode(1);
	TreeNode *node1 = new TreeNode(2);
	TreeNode *node2 = new TreeNode(3);

	TreeNode *node3 = new TreeNode(4);
	TreeNode *node4 = new TreeNode(5);
	TreeNode *node6 = new TreeNode(6);

	root->left = node1;
	root->right = node4;

	node1->left = node2;
	node1->right = node3;

	node4->right = node6;

	flatten(root);

	return 0;
}
