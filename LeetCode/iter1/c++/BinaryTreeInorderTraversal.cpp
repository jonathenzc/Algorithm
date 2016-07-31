#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*************************** 递归版本 ****************************/
//void inorderHelper(TreeNode *root, vector<int>& v)
//{
//	if (root != NULL)
//	{
//		inorderHelper(root->left,v);
//		v.push_back(root->val);
//		inorderHelper(root->right,v);
//	}
//}
//
//vector<int> inorderTraversal(TreeNode* root) 
//{
//	vector<int> v;
//
//	inorderHelper(root,v);
//
//	return v;
//}

/*************************** 迭代版本 ****************************/
vector<int> inorderTraversal(TreeNode* root)
{
	vector<int> v;
	stack<TreeNode*> s;
	s.push(root);

	//当左右节点都为空时，可添加该节点的值，
	//则右节点不为空时，先压入右节点，接着将当前节点（中间节点）的左右节点赋为空，并压入栈
	//最后当左节点不为空时，压入栈
	while (!s.empty())
	{
		TreeNode *node = s.top();
		s.pop();

		if (node != NULL)
		{
			if (node->left == NULL && node->right == NULL)
				v.push_back(node->val);
			else
			{
				if (node->right != NULL)
					s.push(node->right);

				TreeNode *leftNode = node->left;
				node->left = NULL;
				node->right = NULL;

				s.push(node);
				if (leftNode != NULL)
					s.push(leftNode);
			}
		}
	}

	return v;
}


int main()
{
	TreeNode *root = new TreeNode(1);
	TreeNode *node1 = new TreeNode(2);
	TreeNode *node2 = new TreeNode(3);
	TreeNode *node3 = new TreeNode(4);
	TreeNode *node4 = new TreeNode(5);
	TreeNode *node5 = new TreeNode(6);

	root->left = node1;
	root->right = node2;
	node1->left = node3;
	node1->right = node4;
	node2->left = node5;

	vector<int> v;
	v = inorderTraversal(root);

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return 0;
}