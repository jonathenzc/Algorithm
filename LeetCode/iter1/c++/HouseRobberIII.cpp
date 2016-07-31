#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int robHelper(TreeNode *root,int &left,int &right) 
{
	if (root == NULL)
		return 0;

	int leftleft = 0, leftright = 0, rightLeft = 0, rightright = 0;
	left = robHelper(root->left,leftleft,leftright);
	right = robHelper(root->right, rightLeft,rightright);

	if (left + right > root->val + leftleft + leftright + rightLeft + rightright)
		return left + right;
	else
		return root->val + leftleft + leftright + rightLeft + rightright;
}

int rob(TreeNode* root) 
{
	int left = 0, right = 0;
	int result = robHelper(root,left,right);

	return result;
}

int main()
{
	TreeNode *root = new TreeNode(2);
	TreeNode *node1 = new TreeNode(1);
	TreeNode *node2 = new TreeNode(3);
	TreeNode *node3 = new TreeNode(4);
	//TreeNode *node4 = new TreeNode(1);
	root->left = node1;
	root->right = node2;

	node1->right = node3;
	//node2->left = node4;

	cout << rob(root);


	return 0;
}