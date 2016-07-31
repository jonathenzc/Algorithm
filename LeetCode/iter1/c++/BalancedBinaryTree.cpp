#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int depth(TreeNode* root)
{
	if (root == NULL)
		return 0;
	else
	{
		int leftDepth = depth(root->left);
		int rightDepth = depth(root->right);

		if (leftDepth > rightDepth)
			return leftDepth + 1;
		else
			return rightDepth + 1;
	}
}

bool isBalanced(TreeNode* root) 
{
	if (root == NULL)
		return true;
	else
	{
		int leftDepth = depth(root->left);
		int rightDepth = depth(root->right);

		if (leftDepth - rightDepth <= 1 && leftDepth - rightDepth >= -1)
			return isBalanced(root->left) && isBalanced(root->right);
		else
			return false;
	}
}

int main()
{
	//构建这样的树
	//        5
	//	     / \
	//	    4   8
	//	   /   / \
	//	  11  13  4
	//	 /  \      \
	//	7    2      1

	TreeNode *node7 = new TreeNode(7);
	TreeNode *node2 = new TreeNode(2);
	TreeNode *node11 = new TreeNode(11);
	node11->left = node7;
	node11->right = node2;

	TreeNode *node4 = new TreeNode(4);
	node4->left = node11;

	TreeNode *node1 = new TreeNode(1);
	TreeNode *nodeAnother4 = new TreeNode(4);
	nodeAnother4->right = node1;

	TreeNode *node13 = new TreeNode(13);
	TreeNode *node8 = new TreeNode(8);
	node8->left = node13;
	node8->right = nodeAnother4;

	TreeNode *root = new TreeNode(5);
	root->left = node4;
	root->right = node8;

	if (isBalanced(root))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
