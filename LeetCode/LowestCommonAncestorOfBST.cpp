#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
	if (root->val < p->val && root->val < q->val)//p��q����root��Ԫ�ش�������������Ѱ��
		return lowestCommonAncestor(root->right, p, q);
	else if (root->val > p->val && root->val > q->val)//p��q����rootԪ��С��������������Ѱ��
		return lowestCommonAncestor(root->left, p, q);
	else //p,q�ֲ���root���ߣ���rootΪ��С��������
		return root;
}

int main()
{
	////������������
	////           6
	////	     /   \
	////	    2     8
	////	   / \   / \
	////	  0   4 7   9
	////         / \
	////        3   5
	TreeNode *node0 = new TreeNode(0);
	TreeNode *node2 = new TreeNode(2);
	TreeNode *node3 = new TreeNode(3);
	TreeNode *node4 = new TreeNode(4);
	TreeNode *node5 = new TreeNode(5);
	TreeNode *node6 = new TreeNode(6);
	TreeNode *node7 = new TreeNode(7);
	TreeNode *node8 = new TreeNode(8);
	TreeNode *node9 = new TreeNode(9);

	node4->left = node3;
	node4->right = node5;

	node2->left = node0;
	node2->right = node4;

	node8->left = node7;
	node8->right = node9;

	node6->left = node2;
	node6->right = node8;

	TreeNode *ancestorNode = lowestCommonAncestor(node6,node3,node4);

	cout << ancestorNode->val;

	return 0;
}