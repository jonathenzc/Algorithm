#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNodeDepth
{
	TreeNode *tNode;
	int currentDepth;
};

int maxDepth(TreeNode* root)
{
	int depthMax = 0;

	if (root != NULL)
	{
		stack<TreeNodeDepth> s;

		TreeNodeDepth tNodeDepth;
		tNodeDepth.currentDepth = 1;
		tNodeDepth.tNode = root;

		s.push(tNodeDepth);

		while (!s.empty())
		{
			tNodeDepth = s.top();
			s.pop();

			TreeNode *treeNode = tNodeDepth.tNode;
			int depth = tNodeDepth.currentDepth;

			//左右节点皆为空指针，即叶子节点
			if (treeNode->left == NULL && treeNode->right == NULL)
			{
				if (depth > depthMax)
					depthMax = depth;
			}
			else
			{
				if (treeNode->right != NULL)
				{
					TreeNodeDepth rightNodeDepth;
					rightNodeDepth.currentDepth = tNodeDepth.currentDepth + 1;
					rightNodeDepth.tNode = treeNode->right;
					s.push(rightNodeDepth);
				}

				if (treeNode->left != NULL)
				{
					TreeNodeDepth leftNodeDepth;
					leftNodeDepth.currentDepth = tNodeDepth.currentDepth + 1;
					leftNodeDepth.tNode = treeNode->left;
					s.push(leftNodeDepth);
				}
			}
		}
	}

	return depthMax;
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

	TreeNode *node7 = new TreeNode(7);
	TreeNode *node2 = new TreeNode(2);
	TreeNode *node11 = new TreeNode(11);
	node11->left = node7;
	node11->right = node2;

	TreeNode *node4 = new TreeNode(4);
	node4->left = node11;

	TreeNode *node1 = new TreeNode(1);
	TreeNode *nodeAnother4 = new TreeNode(4);
	nodeAnother4->right = node1;

	TreeNode *node13 = new TreeNode(13);
	TreeNode *node8 = new TreeNode(8);
	node8->left = node13;
	node8->right = nodeAnother4;

	TreeNode *root = new TreeNode(5);
	root->left = node4;
	root->right = node8;

	cout << maxDepth(node8);

	return 0;
}