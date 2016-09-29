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

	int sumOfLeftLeaves(TreeNode* root) {
		int sum = 0;

		if (root != NULL)
			sum = helper(root->left,true) + helper(root->right,false);

		return sum;
	}

private:
	int helper(TreeNode *node, bool isFromLeft)
	{
		if (node != NULL)
		{
			if (isFromLeft && node->left == NULL && node->right == NULL)
					return node->val;
			else
				return helper(node->left, true) + helper(node->right, false);
		}
		else
			return 0;
	}
	

};

int main()
{
	Solution s;

	TreeNode *root = new TreeNode(3);
	TreeNode *node1 = new TreeNode(9);
	TreeNode *node2 = new TreeNode(20);
	TreeNode *node3 = new TreeNode(15);
	TreeNode *node4 = new TreeNode(7);

	root->left = node1;
	root->right = node2;

	node2->left = node3;
	node2->right = node4;

	cout<<s.sumOfLeftLeaves(root);

	return 0;

}