#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (root == NULL)
			return true;

		inOrder(root);

		int start = 1;
		int preItem = v[0];
		bool ret = true;
		while (start < v.size())
		{
			if (preItem >= v[start])
			{
				ret = false;
				break;
			}

			preItem = v[start++];
		}

		return ret;
	}
private:
	vector<int> v;

	void inOrder(TreeNode * root)
	{
		if (root != NULL)
		{
			inOrder(root->left);
			v.push_back(root->val);
			inOrder(root->right);
		}
	}
};

int main()
{
	//TreeNode *root = new TreeNode(10);
	//TreeNode *node1 = new TreeNode(5);
	//TreeNode *node2 = new TreeNode(15);
	//TreeNode *node3 = new TreeNode(6);
	//TreeNode *node4 = new TreeNode(20);

	//root->left = node1;
	//root->right = node2;

	//node2->left = node3;
	//node2->right = node4;

	TreeNode *root = new TreeNode(3);
	TreeNode *node1 = new TreeNode(1);
	TreeNode *node2 = new TreeNode(5);
	TreeNode *node3 = new TreeNode(0);
	TreeNode *node4 = new TreeNode(2);
	TreeNode *node5 = new TreeNode(4);
	TreeNode *node6 = new TreeNode(6);

	root->left = node1;
	root->right = node2;

	node1->left = node3;
	node1->right = node4;

	node2->left = node5;
	node2->right = node6;

	Solution s;

	if (s.isValidBST(root))
		cout << "Yes\n";
	else
		cout << "No\n";

	return 0;
}