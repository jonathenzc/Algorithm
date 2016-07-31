#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

void treePathHelper(TreeNode *root,string s,vector<string>& v)
{
	if (root != NULL)
	{
		string numS;
		stringstream ss;
		ss << root->val;
		ss >> numS;

		if (root->left == NULL && root->right == NULL)//叶子节点
		{
			s = s + numS;
			v.push_back(s);
		}
		else
		{
			s = s + numS + "->";

			if (root->left != NULL)
				treePathHelper(root->left, s, v);

			if (root->right != NULL)
				treePathHelper(root->right, s, v);
		}
	}
}

vector<string> binaryTreePaths(TreeNode* root) 
{
	vector<string> v;

	treePathHelper(root,"",v);

	return v;
}

int main()
{
	TreeNode *root = new TreeNode(11);
	TreeNode *node1 = new TreeNode(2);
	TreeNode *node2 = new TreeNode(3);

	TreeNode *node3 = new TreeNode(4);
	TreeNode *node4 = new TreeNode(5);
	TreeNode *node6 = new TreeNode(4);

	root->left = node1;
	root->right = node2;

	node1->left = node3;
	node1->right = node4;

	node2->right = node6;

	vector<string> v = binaryTreePaths(root);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i]<<endl;
	}

	return 0;
}
