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

/*************************** �ݹ�汾 ****************************/
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

/*************************** �����汾 ****************************/
vector<int> inorderTraversal(TreeNode* root)
{
	vector<int> v;
	stack<TreeNode*> s;
	s.push(root);

	//�����ҽڵ㶼Ϊ��ʱ������Ӹýڵ��ֵ��
	//���ҽڵ㲻Ϊ��ʱ����ѹ���ҽڵ㣬���Ž���ǰ�ڵ㣨�м�ڵ㣩�����ҽڵ㸳Ϊ�գ���ѹ��ջ
	//�����ڵ㲻Ϊ��ʱ��ѹ��ջ
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