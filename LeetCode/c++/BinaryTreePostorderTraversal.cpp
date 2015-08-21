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
	int visitCnt; //记录被访问的次数
	stackEle(TreeNode *theNode, int cnt) :node(theNode), visitCnt(cnt) {}
};

/*******************************递归版本******************************/
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

/*******************************迭代版本******************************/
vector<int> postorderTraversal(TreeNode* root) {
	vector<int> v;
	if (root == NULL)
		return v;

	stack<stackEle> s;
	stackEle rootEle(root,0);
	s.push(rootEle);

	//只要栈头的节点的左右孩子都不为空且访问次数为0，那么就压入右孩子，再左孩子，并更新访问的次数
	//如果访问次数不为0，那么就压入vector，并弹栈
	//如果都为空，那么就压入vector，并弹栈
	while (!s.empty())
	{
		stackEle ele = s.top();
		TreeNode *node = ele.node;
		if (ele.visitCnt == 0)//访问次数为0，就先压入右孩子，再压入左孩子
		{
			s.top().visitCnt = 1;
			if(node->left == NULL && node->right == NULL)//左右节点均为空，就压入容器
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