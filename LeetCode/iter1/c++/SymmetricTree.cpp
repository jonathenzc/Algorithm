#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSubTreeSymmetric(TreeNode* leftTree, TreeNode* rightTree)
{
	if (leftTree != NULL && rightTree != NULL)
	{
		if (leftTree->val == rightTree->val)
		{
			//����ߵ���ߺ��ұߵ��ұ��ǶԳƣ�����ߵ��ұߺ��ұߵ�����ǶԳ�ʱ���������ǶԳ�
			if (isSubTreeSymmetric(leftTree->left, rightTree->right) &&
				isSubTreeSymmetric(leftTree->right, rightTree->left))
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else if (leftTree != NULL || rightTree != NULL)
		return false;
}

bool isSymmetric(TreeNode* root) 
{
	if (root == NULL)
		return true;
	else
	{
		if (root->left != NULL && root->right != NULL)
			return isSubTreeSymmetric(root->left, root->right);
		else if (root->left == NULL && root->right == NULL)
			return true;
		else
			return false;
	}
}

int main()
{
	//������������
	//         5
	//	     /   \
	//	    4     4
	//	   / \   / \
	//	  1   2 2   1
	//	 /           \
	//	7             7

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

	if (isSymmetric(root))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}