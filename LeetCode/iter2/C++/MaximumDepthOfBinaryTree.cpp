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

	int maxDepth(TreeNode* root) {
		if (root == NULL)
			return 0;

		if (root->left == NULL && root->right == NULL)
			return 1;

		int leftMaxDepth = INT_MIN, rightMaxDepth = INT_MIN;

		if (root->left != NULL)
			leftMaxDepth = getMaxDepth(root->left, 2);

		if (root->right != NULL)
			rightMaxDepth = getMaxDepth(root->right, 2);

		return max(leftMaxDepth, rightMaxDepth);
	}
private:
	int getMaxDepth(TreeNode* root, int depth)
	{
		if (root->left == NULL && root->right == NULL)
			return depth;

		int leftMaxDepth = INT_MIN, rightMaxDepth = INT_MIN;

		if (root->left != NULL)
			leftMaxDepth = getMaxDepth(root->left, depth + 1);

		if (root->right != NULL)
			rightMaxDepth = getMaxDepth(root->right, depth + 1);

		return max(leftMaxDepth, rightMaxDepth);
	}
};

int main()
{
	TreeNode* root = new TreeNode(1);
	TreeNode* node1 = new TreeNode(2);
	TreeNode* node2 = new TreeNode(3);
	TreeNode* node3 = new TreeNode(4);
	TreeNode* node4 = new TreeNode(5);

	root->left = node1;
	root->right = node2;

	node2->right = node3;
	node3->right = node4;

	Solution s;

	cout << s.maxDepth(root);

	return 0;
}
