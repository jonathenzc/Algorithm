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

vector<TreeNode*> helper(int left, int right)
{
	vector<TreeNode*> v;

	if (left == right)
	{
		TreeNode *root = new TreeNode(left);
		v.push_back(root);
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
					TreeNode *node = new TreeNode(i);
					node->left = leftNode;
					node->right = rightNode;
					v.push_back(node);
				}
			}
		}
	}
	else
		v.push_back(NULL);

	return v;
}

vector<TreeNode*> generateTrees(int n) {
	vector<TreeNode*> v;
	if (n == 0)
		return v;

	return helper(1,n);
}

void innerPrint(TreeNode *node)
{
	if (node != NULL)
	{
		innerPrint(node->left);
		cout << node->val << " ";
		innerPrint(node->right);
	}
}

void testPrint(vector<TreeNode*> v)
{
	for (auto node : v)
	{
		innerPrint(node);
		cout << endl;
	}
}

int main()
{
	vector<TreeNode*> v = generateTrees(3);

	testPrint(v);

	return 0;
}