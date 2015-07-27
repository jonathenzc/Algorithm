#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//void changeLeftAndRight(TreeNode *left, TreeNode *right)
//{
//	if (left != NULL && right != NULL)
//	{
//		int temp = left->val;
//		left->val = right->val;
//		right->val = temp;
//
//		//左边的左边和右边的右边比
//		if (left->left == NULL && right->right != NULL)
//		{
//			left->left = right->right;
//			right->right = NULL;
//		}
//		else if (left->left != NULL && right->right == NULL)
//		{
//			right->right = left->left;
//			left->left = NULL;
//		}
//
//		changeLeftAndRight(left->left,right->right);
//
//		//左边的右边和右边的左边比
//		if (left->right == NULL && right->left != NULL)
//		{
//			left->right = right->left;
//			right->left = NULL;
//		}
//		else if (left->right != NULL && right->left == NULL)
//		{
//			right->left = left->right;
//			left->right = NULL;
//		}
//
//		changeLeftAndRight(left->right,right->left);
//	}
//	else if (left == NULL && right != NULL)//重复root的过程
//	{
//		if (right->left != NULL && right->right == NULL)
//		{
//			right->right = right->left;
//			right->left = NULL;
//		}
//		else if (right->left == NULL && right->right != NULL)
//		{
//			right->left = right->right;
//			right->right = NULL;
//		}
//
//		changeLeftAndRight(right->left, right->right);
//	}
//	else if (left != NULL && right == NULL)
//	{
//		if (left->left != NULL && left->right == NULL)
//		{
//			left->right = left->left;
//			left->left = NULL;
//		}
//		else if (left->left == NULL && left->right != NULL)
//		{
//			left->left = left->right;
//			left->right = NULL;
//		}
//
//		changeLeftAndRight(left->left,left->right);
//	}
//}
//
//TreeNode* invertTree(TreeNode* root) 
//{
//	if (root != NULL)
//	{
//		if (root->left != NULL && root->right == NULL)
//		{
//			root->right = root->left;
//			root->left = NULL;
//		}
//		else if (root->left == NULL && root->right != NULL)
//		{
//			root->left = root->right;
//			root->right = NULL;
//		}
//
//		changeLeftAndRight(root->left, root->right);
//	}
//
//	return root;
//}

////迭代版本
//TreeNode* invertTree(TreeNode* root)
//{
//	stack<TreeNode*> s;
//	s.push(root);
//
//	while (!s.empty())
//	{
//		TreeNode* fatherNode = s.top();
//		s.pop();
//
//		if (fatherNode != NULL)
//		{
//			s.push(fatherNode->left);
//			s.push(fatherNode->right);
//
//			//交换左右子树
//			TreeNode *tempNode = fatherNode->left;
//			fatherNode->left = fatherNode->right;
//			fatherNode->right = tempNode;
//		}
//	}
//
//	return root;
//}

//递归版本
TreeNode* invertTree(TreeNode* root)
{
	if (root!=NULL)
	{
		invertTree(root->left);
		invertTree(root->right);

		//交换左右子树
		TreeNode *temp = root->left;
		root->left = root->right;
		root->right = temp;
	}

	return root;
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

	//TreeNode *node7 = new TreeNode(7);
	//TreeNode *node2 = new TreeNode(2);
	//TreeNode *node11 = new TreeNode(11);
	//node11->left = node7;
	//node11->right = node2;

	//TreeNode *node4 = new TreeNode(4);
	//node4->left = node11;

	//TreeNode *node1 = new TreeNode(1);
	//TreeNode *nodeAnother4 = new TreeNode(4);
	//nodeAnother4->right = node1;

	//TreeNode *node13 = new TreeNode(13);
	//TreeNode *node8 = new TreeNode(8);
	//node8->left = node13;
	//node8->right = nodeAnother4;

	//TreeNode *root = new TreeNode(5);
	////root->left = node4;
	//root->right = node8;


	////构建这样的树
	////           5
	////	     /   \
	////	    4     8
	////	   / \   / \
	////	  11  1 3   6
	//TreeNode *node11 = new TreeNode(11);
	//TreeNode *node1 = new TreeNode(1);
	//TreeNode *node3 = new TreeNode(3);
	//TreeNode *node6 = new TreeNode(6);
	//TreeNode *node8 = new TreeNode(8);
	//TreeNode *node4 = new TreeNode(4);

	//node4->left = node11;
	//node4->right = node1;

	//node8->left = node3;
	//node8->right = node6;

	//TreeNode *node5 = new TreeNode(5);
	//node5->left = node4;
	//node5->right = node8;

	//构建这样的树
	//         1
	//	     /   \
	//	    5     4
	//	   /     
	//	  2  
	//   /
	//  3
	TreeNode *node1 = new TreeNode(1);
	TreeNode *node2 = new TreeNode(2);
	TreeNode *node3 = new TreeNode(3);
	TreeNode *node4 = new TreeNode(4);
	TreeNode *node5 = new TreeNode(5);


	node2->left = node3;
	node5->left = node2;
	node1->left = node5;
	node1->right = node4;

	TreeNode *invertedTree = invertTree(node1);

	cout << "Done";

	return 0;
}