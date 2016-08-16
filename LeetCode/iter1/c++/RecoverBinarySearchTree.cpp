#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traverse(TreeNode *root, TreeNode *&preNode, TreeNode *&firstEle, TreeNode *&secondEle)
{
	if (root != NULL)
	{
		traverse(root->left,preNode,firstEle,secondEle);

		//找出需要交换的两个节点
		if (firstEle == NULL && preNode != NULL && preNode->val > root->val) //仍未找到第一个节点
			firstEle = preNode;

		if (firstEle != NULL && preNode != NULL && preNode->val > root->val) //找第二个元素
			secondEle = root;

		preNode = root;

		traverse(root->right, preNode, firstEle, secondEle);
	}
}

void recoverTree(TreeNode* root) {
	TreeNode *firstEle = NULL;
	TreeNode *secondEle = NULL;
	TreeNode *preNode = NULL;

	traverse(root, preNode, firstEle, secondEle);

	int tmp = firstEle->val;
	firstEle->val = secondEle->val;
	secondEle->val = tmp;
}

void innerPrint(TreeNode *node)
{
	if (node != NULL)
	{
		innerPrint(node->left);
		cout << node->val << " ";
		innerPrint(node->right); 
	}
}

void testPrint(vector<TreeNode*> v)
{
	for (auto node : v)
	{
		innerPrint(node);
		cout << endl;
	}
}

int main()
{
	TreeNode* two = new TreeNode(2);
	TreeNode* one = new TreeNode(1);
	TreeNode* three = new TreeNode(3);
	TreeNode* four = new TreeNode(4);

	two->left = one;
	two->right = three;

	three->left = four;

	cout << "Before change \n";
	innerPrint(two);

	cout << "\nAfter change\n";
	recoverTree(two);
	innerPrint(two);


	//TreeNode* two = new TreeNode(2);
	//TreeNode* one = new TreeNode(1);
	//TreeNode* three = new TreeNode(3);

	//two->left = three;
	//two->right = one;

	//cout << "Before change \n";
	//innerPrint(two);

	//cout << "\nAfter change\n";
	//recoverTree(two);
	//innerPrint(two);

	return 0;
}