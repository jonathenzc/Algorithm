#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

int getMax(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int maxPathHelper(TreeNode *root,int&max)
{
	if (root == NULL)
		return 0;

	int left = maxPathHelper(root->left, max);
	int right = maxPathHelper(root->right,max);

	//比较1. 左边最大值+当前节点；2. 右边最大值+当前节点； 3.当前节点，
	int curmax = getMax(getMax(left+root->val,right+root->val),root->val);
	//比较1.考虑当前节点只连其中一个（上面的结果）和 2.左右节点都相连的情况
	int maxInclude = getMax(curmax, root->val + left + right);
	max = getMax(maxInclude, max);

	return curmax;
}

int maxPathSum(TreeNode* root) {
	int max = INT_MIN;

	maxPathHelper(root, max);

	return max;
}

int main()
{
	TreeNode *root = new TreeNode(1);
	TreeNode *node1 = new TreeNode(2);
	TreeNode *node2 = new TreeNode(3);

	TreeNode *node3 = new TreeNode(4);
	TreeNode *node4 = new TreeNode(5);
	TreeNode *node6 = new TreeNode(4);

	root->left = node1;
	root->right = node2;

	node1->left = node3;
	node1->right = node4;

	node2->right = node6;

	cout << maxPathSum(root);

	return 0;
}
