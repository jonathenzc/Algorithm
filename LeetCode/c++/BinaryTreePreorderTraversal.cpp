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

/************************ตÝน้**********************/
//void preorderHelper(TreeNode* root, vector<int>& v)
//{
//	if (root != NULL)
//	{
//		v.push_back(root->val);
//		preorderHelper(root->left,v);
//		preorderHelper(root->right,v);
//	}
//}
//
//vector<int> preorderTraversal(TreeNode* root) {
//	vector<int> v;
//
//	preorderHelper(root,v);
//
//	return v;
//}

/************************ตÝน้**********************/
vector<int> preorderTraversal(TreeNode* root) {
	vector<int> v;
	stack<TreeNode*> s;
	s.push(root);

	while (!s.empty())
	{
		TreeNode *node = s.top();
		s.pop();

		if (node != NULL)
		{
			v.push_back(node->val);
			s.push(node->right);
			s.push(node->left);
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

	//root->left = node1;
	root->right = node2;
	//node1->left = node3;
	//node1->right = node4;
	node2->left = node5;

	vector<int> v;
	v = preorderTraversal(root);

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return 0;
}