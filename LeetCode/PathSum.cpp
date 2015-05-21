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

struct TreeNodeSum
{
	TreeNode *tNode;
	int sum;
};


bool hasPathSum(TreeNode* root, int sum) 
{
	bool isSumFound = false;

	if (root != NULL)
	{
		stack<TreeNodeSum> s;

		TreeNodeSum tNodeSum;
		tNodeSum.sum = root->val;
		tNodeSum.tNode = root;
		
		s.push(tNodeSum);

		while (!s.empty())
		{
			tNodeSum = s.top();
			s.pop();

			TreeNode *treeNode = tNodeSum.tNode;
			int nodeSum = tNodeSum.sum;

			//左右节点皆为空指针，即叶子节点
			if (treeNode->left == NULL && treeNode->right == NULL)
			{
				if (nodeSum == sum)
				{
					isSumFound = true;
					break;
				}
			}
			else
			{
				if (treeNode->right != NULL)
				{
					TreeNodeSum rightNodeSum;
					rightNodeSum.sum = tNodeSum.sum + treeNode->right->val;
					rightNodeSum.tNode = treeNode->right;
					s.push(rightNodeSum);
				}

				if (treeNode->left != NULL)
				{
					TreeNodeSum leftNodeSum;
					leftNodeSum.sum = tNodeSum.sum + treeNode->left->val;
					leftNodeSum.tNode = treeNode->left;
					s.push(leftNodeSum);
				}
			}
		}
	}

	return isSumFound;
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

	TreeNode *node1= new TreeNode(1);
	TreeNode *nodeAnother4 = new TreeNode(4);
	nodeAnother4->right = node1;

	TreeNode *node13 = new TreeNode(13);
	TreeNode *node8 = new TreeNode(8);
	node8->left = node13;
	node8->right = nodeAnother4;

	TreeNode *root = new TreeNode(5);
	root->left = node4;
	root->right = node8;

	if (hasPathSum(root, 80))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}