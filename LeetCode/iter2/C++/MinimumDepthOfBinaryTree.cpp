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

	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;

		if (root->left == NULL && root->right == NULL)
			return 1;

		int leftMinDepth = INT_MAX, rightMinDepth = INT_MAX;

		if(root->left != NULL)
			leftMinDepth = getMinDepth(root->left, 2);

		if (root->right != NULL)
			rightMinDepth = getMinDepth(root->right, 2);

		return min(leftMinDepth,rightMinDepth);
	}
private:
	int getMinDepth(TreeNode* root,int depth)
	{
		if (root->left == NULL && root->right == NULL)
			return depth;

		int leftMinDepth = INT_MAX, rightMinDepth = INT_MAX;

		if (root->left != NULL)
			leftMinDepth = getMinDepth(root->left, depth+1);

		if (root->right != NULL)
			rightMinDepth = getMinDepth(root->right, depth+1);

		return min(leftMinDepth, rightMinDepth);
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

	cout << s.minDepth(root);

	return 0;
}