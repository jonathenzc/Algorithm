#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameSubTree(TreeNode* tree1, TreeNode* tree2)
{
	if (tree1 != NULL && tree2 != NULL)
	{
		if (tree1->val == tree2->val)
		{
			if (isSameSubTree(tree1->left, tree2->left) &&
				isSameSubTree(tree1->right, tree2->right))
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else if (tree1 != NULL || tree2 != NULL)
		return false;
	else
		return true;
}

bool isSameTree(TreeNode* p, TreeNode* q) 
{
	if (p == NULL && q == NULL)
		return true;
	else if (p != NULL && q != NULL)
	{
		//先判断两个根节点是否相同
		if (p->val != q->val)
			return false;
		else
			return (isSameSubTree(p->left,q->left) && isSameSubTree(p->right,q->right));
	}
	else//有一个是空节点，另一个不是空节点
		return false;
}

TreeNode* BuildTree()
{
	TreeNode *leftNode7 = new TreeNode(7);
	TreeNode *rightNode7 = new TreeNode(7);

	TreeNode *leftNode1 = new TreeNode(1);
	TreeNode *rightNode1 = new TreeNode(1);

	leftNode1->left = leftNode7;
	rightNode1->right = rightNode7;

	TreeNode *leftNode2 = new TreeNode(2);
	TreeNode *rightNode2 = new TreeNode(2);

	TreeNode *leftNode4 = new TreeNode(4);
	leftNode4->left = leftNode1;
	leftNode4->right = leftNode2;

	TreeNode *rightNode4 = new TreeNode(4);
	rightNode4->left = rightNode2;
	rightNode4->right = rightNode1;

	TreeNode *root = new TreeNode(5);
	root->left = leftNode4;
	root->right = rightNode4;

	return root;
}

int main()
{
	//构建这样的树
	//         5
	//	     /   \
	//	    4     4
	//	   / \   / \
	//	  1   2 2   1
	//	 /           \
	//	7             7

	TreeNode *tree1 = BuildTree();
	//TreeNode *tree2 = BuildTree();

	TreeNode *leftNode7 = new TreeNode(7);
	TreeNode *rightNode7 = new TreeNode(7);

	TreeNode *leftNode1 = new TreeNode(1);
	TreeNode *rightNode1 = new TreeNode(1);

	//leftNode1->left = leftNode7;
	//rightNode1->right = rightNode7;

	TreeNode *leftNode2 = new TreeNode(2);
	TreeNode *rightNode2 = new TreeNode(2);

	TreeNode *leftNode4 = new TreeNode(4);
	leftNode4->left = leftNode1;
	leftNode4->right = leftNode2;

	TreeNode *rightNode4 = new TreeNode(4);
	rightNode4->left = rightNode2;
	rightNode4->right = rightNode1;

	TreeNode *root = new TreeNode(5);
	root->left = leftNode4;
	root->right = rightNode4;


	if (isSameTree(tree1,root))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}