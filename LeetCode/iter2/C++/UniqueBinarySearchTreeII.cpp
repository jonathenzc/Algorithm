#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> helper(int left,int right) {
	vector<TreeNode*> ret;

	if (left == right)
	{
		TreeNode *root = new TreeNode(left);
		ret.push_back(root);
	}
	else if (left < right)
	{
		for (int i = left; i <= right; i++)
		{
			vector<TreeNode*> leftV = helper(left, i - 1);
			vector<TreeNode*> rightV = helper(i + 1, right);

			for (auto leftNode : leftV)
			{
				for (auto rightNode : rightV)
				{
					TreeNode *root = new TreeNode(i);
					root->left = leftNode;
					root->right = rightNode;
					ret.push_back(root);
				}
			}
		}
	}
	else
		ret.push_back(NULL);

	return ret;
}

vector<TreeNode*> generateTrees(int n) {
	if (n == 0)
	{
		vector<TreeNode*> v;
		return v;
	}

	return helper(1,n);
}

void outputTreeNode(TreeNode *root)
{
	if (root != NULL)
	{
		outputTreeNode(root->left);
		cout << root->val<<" ";
		outputTreeNode(root->right);
	}
}

void testPrint(int n)
{
	auto v = generateTrees(n);
	for (auto node : v)
	{
		outputTreeNode(node);
		cout << endl;
	}
}

int main()
{
	testPrint(3);

	return 0;
}