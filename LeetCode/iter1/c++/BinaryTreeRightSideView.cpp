#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

struct TreeNodeLevel {
	TreeNode *node;
	int level;
};

vector<int> rightSideView(TreeNode* root) {
	vector<int> v;

	if (root != NULL)
	{
		queue<TreeNodeLevel> q;
		TreeNodeLevel rootLeveL;
		rootLeveL.level = 1;
		rootLeveL.node = root;

		q.push(rootLeveL);

		int crtLevel = 1;

		TreeNode *lastNode = NULL;

		while (!q.empty())
		{
			TreeNodeLevel topLevel = q.front();
			q.pop();

			TreeNode *topNode = topLevel.node;

			//将当前层的最后一个压入容器中
			if (topLevel.level != crtLevel)
			{
				v.push_back(lastNode->val);
				crtLevel++;
				lastNode = topNode;
			}
			else
			{
				lastNode = topNode;
			}

			if (topNode->left != NULL)
			{
				TreeNodeLevel leftLevel;
				leftLevel.level = topLevel.level + 1;
				leftLevel.node = topNode->left;
				q.push(leftLevel);
			}

			if (topNode->right != NULL)
			{
				TreeNodeLevel rightLevel;
				rightLevel.level = topLevel.level + 1;
				rightLevel.node = topNode->right;
				q.push(rightLevel);
			}
		}

		if(lastNode != NULL)
			v.push_back(lastNode->val);
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
	TreeNode *node6 = new TreeNode(6);

	//root->left = node1;
	//root->right = node2;

	//node1->left = node3;
	//node1->right = node4;

	//node2->right = node6;

	vector<int> v = rightSideView(root);

	for (int i = 0; i < v.size();i++)
		cout << v[i]<<" ";

	return 0;
}
