#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

//返回从根节点到该节点的路径
bool getPath(TreeNode* root, TreeNode *p, vector<TreeNode*>& v)
{
	if (root == NULL)
		return false;

	if (root == p)
	{
		v.push_back(p);
		return true;
	}
	else
	{
		v.push_back(root);

		bool isFound = false;
		if(root->left != NULL)
			isFound = getPath(root->left, p, v);

		if (!isFound)
		{
			if (root->right != NULL)
				isFound = getPath(root->right,p,v);
		}

		if (!isFound)
			v.pop_back();

		return isFound;
	}
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	bool pIsFound = false;
	bool qIsFound = false;


	vector<TreeNode*> pV; 
	getPath(root, p,  pV);

	vector<TreeNode*> qV;
	getPath(root, q,  qV);

	//for (int i = 0; i < pV.size(); i++)
	//	cout << pV[i]->val << " ";

	//cout << endl;

	//for (int i = 0; i < qV.size(); i++)
	//	cout << qV[i]->val << " ";

	//找出vector中第一个不相同的节点，那么前一个节点就是共同的
	TreeNode *resultNode = NULL;
	int	i = 0, j = 0;
	while (i < pV.size() && j < qV.size())
	{
		TreeNode *pIter = pV[i];
		TreeNode *qIter = qV[j];

		if (pIter != qIter)
		{
			resultNode = pV[i - 1];
			break;
		}

		i++;
		j++;
	}

	if (resultNode == NULL)
		resultNode = pV[i - 1];

	return resultNode;
}

int main()
{
	TreeNode *root = new TreeNode(1);
	TreeNode *node1 = new TreeNode(2);
	TreeNode *node2 = new TreeNode(3);

	TreeNode *node3 = new TreeNode(4);
	TreeNode *node4 = new TreeNode(5);
	TreeNode *node6 = new TreeNode(6);

	root->left = node1;
	root->right = node2;

	node1->left = node3;
	node1->right = node4;

	node2->right = node6;

	TreeNode *resultNode = lowestCommonAncestor(root, node6, node4);
	cout << resultNode->val;

	return 0;
}
