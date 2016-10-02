#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <queue>
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

	bool isBalanced(TreeNode* root) {
		if (root == NULL)
			return true;

		int leftHeight = 1;
		int rightHeight = 1;

		if (!subTreeBalanced(root->left, leftHeight))
			return false;

		if (!subTreeBalanced(root->right, rightHeight))
			return false;

		if (abs(leftHeight - rightHeight) > 1)
			return false;

		return true;
	}
private:
	bool subTreeBalanced(TreeNode *root,int &height)
	{
		if (root == NULL)
			return true;

		int leftHeight = 1;
		int rightHeight = 1;
		bool ret = true;

		if (!subTreeBalanced(root->left, leftHeight))
			ret = false;

		if (!subTreeBalanced(root->right, rightHeight))
			ret = false;

		if (abs(leftHeight - rightHeight) > 1)
			ret = false;

		height += max(leftHeight,rightHeight);

		return ret;
	}
};

int main()
{
	TreeNode* root = new TreeNode(1);
	TreeNode* node1 = new TreeNode(2);
	TreeNode* node2 = new TreeNode(3);

	root->right = node1;
	node1->right = node2;

	Solution s;

	if (s.isBalanced(root))
		cout << "Yes\n";
	else
		cout << "No\n";

	return 0;
}