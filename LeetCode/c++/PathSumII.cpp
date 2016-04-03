#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

void pathSumHelper(TreeNode* root, int sum,int pathSum,vector<int> pathV,vector<vector<int>> &v)
{
	if (root != NULL)
	{
		if (root->left == NULL && root->right == NULL)//叶子节点
		{
			if (pathSum + root->val == sum)
			{
				pathV.push_back(root->val);
				v.push_back(pathV);
			}
		}
		else
		{
			pathV.push_back(root->val);
			pathSum += root->val;
			if (root->left != NULL)
				pathSumHelper(root->left,sum,pathSum,pathV,v);

			if (root->right != NULL)
				pathSumHelper(root->right, sum, pathSum, pathV, v);
		}
	}
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
	vector<vector<int>> v;
	vector<int> pathV;
	pathSumHelper(root,sum,0, pathV,v);

	return v;
}

int main()
{
	TreeNode *root = new TreeNode(1);
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

	vector<vector<int>> v = pathSum(root,8);;

	for (int i = 0; i < v.size(); i++)
	{
		vector<int> innerV = v[i];
		for (int j = 0; j < innerV.size(); j++)
		{
			cout << innerV[j] << " ";
		}
		cout << endl;
	}

	return 0;
}
