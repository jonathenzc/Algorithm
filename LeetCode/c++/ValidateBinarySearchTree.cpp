#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBSTHelper(TreeNode *root, long min, long max)
{
	if (root == NULL)
		return true;
	else
	{
		if (root->val > min && root->val < max)
			return isValidBSTHelper(root->left, min, root->val) && isValidBSTHelper(root->right, root->val, max);
		else
			return false;
	}
}

bool isValidBST(TreeNode* root)
{
	if (root == NULL)
		return true;

	if (root->left == NULL && root->right == NULL)
		return true;
	else
	{
		return isValidBSTHelper(root->left, LONG_MIN, root->val) && isValidBSTHelper(root->right, root->val, LONG_MAX);
	}
}

int main()
{
	TreeNode *root = new TreeNode(0);
	TreeNode *node1 = new TreeNode(-1);
	TreeNode *node2 = new TreeNode(15);
	TreeNode *node3 = new TreeNode(4);
	TreeNode *node4 = new TreeNode(20);

	root->left = node1;
	//root->right = node2;

	//node2->left = node3;
	//node2->right = node4;


	if (isValidBST(root))
		cout << "true";
	else
		cout << "false";


	return 0;
}