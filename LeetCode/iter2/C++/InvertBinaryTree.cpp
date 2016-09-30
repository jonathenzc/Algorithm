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

	TreeNode* invertTree(TreeNode* root) {

		return helper(root);
	}

private:
	TreeNode* helper(TreeNode *root)
	{
		if (root == NULL)
			return root;

		TreeNode *tmp = root->left;
		root->left = helper(root->right);
		root->right = helper(tmp);
		
		return root;
	}
};

int main()
{
	Solution s;

	TreeNode *root = new TreeNode(4);
	TreeNode *node1 = new TreeNode(2);
	TreeNode *node2 = new TreeNode(7);
	TreeNode *node3 = new TreeNode(1);
	TreeNode *node4 = new TreeNode(3);
	TreeNode *node5 = new TreeNode(6);
	TreeNode *node6 = new TreeNode(9);

	root->left = node1;
	root->right = node2;

	node1->left = node3;
	node1->right = node4;

	node2->left = node5;
	node2->right = node6;



	s.invertTree(root);

	return 0;

}