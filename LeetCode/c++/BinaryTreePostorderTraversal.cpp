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

struct stackEle {
	TreeNode *node;
	int visitCnt; //��¼�����ʵĴ���
	stackEle(TreeNode *theNode, int cnt) :node(theNode), visitCnt(cnt) {}
};

/*******************************�ݹ�汾******************************/
//void postOrderHelper(TreeNode* root,vector<int> &v)
//{
//	if (root != NULL)
//	{
//		postOrderHelper(root->left,v);
//		postOrderHelper(root->right, v);
//		v.push_back(root->val);
//	}
//}
//
//vector<int> postorderTraversal(TreeNode* root) {
//	vector<int> v;
//
//	postOrderHelper(root,v);
//
//	return v;
//}

/*******************************�����汾******************************/
vector<int> postorderTraversal(TreeNode* root) {
	vector<int> v;
	if (root == NULL)
		return v;

	stack<stackEle> s;
	stackEle rootEle(root,0);
	s.push(rootEle);

	//ֻҪջͷ�Ľڵ�����Һ��Ӷ���Ϊ���ҷ��ʴ���Ϊ0����ô��ѹ���Һ��ӣ������ӣ������·��ʵĴ���
	//������ʴ�����Ϊ0����ô��ѹ��vector������ջ
	//�����Ϊ�գ���ô��ѹ��vector������ջ
	while (!s.empty())
	{
		stackEle ele = s.top();
		TreeNode *node = ele.node;
		if (ele.visitCnt == 0)//���ʴ���Ϊ0������ѹ���Һ��ӣ���ѹ������
		{
			s.top().visitCnt = 1;
			if(node->left == NULL && node->right == NULL)//���ҽڵ��Ϊ�գ���ѹ������
			{
				v.push_back(node->val);
				s.pop();
			}
			if (node->right != NULL)
				s.push(stackEle(node->right, 0));
		    if (node->left != NULL)
				s.push(stackEle(node->left, 0));
		}
		else
		{
			v.push_back(node->val);
			s.pop();
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
	v = postorderTraversal(root);

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return 0;
}