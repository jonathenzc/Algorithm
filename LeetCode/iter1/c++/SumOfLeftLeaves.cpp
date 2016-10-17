#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>

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
		sum = 0;

		helper(root);

		return sum;
	}
private:
	int sum;

	void helper(TreeNode *root)
	{
		if (root != NULL)
		{
			if (root->left != NULL)
			{
				if (root->left->left == NULL && root->left->right == NULL) //leaf node
					sum += root->left->val;
				else
					helper(root->left);
			}

			helper(root->right);
		}
	}
};

int main(void)
{
	TreeNode *root = new TreeNode(1);
	TreeNode *node1 = new TreeNode(2);
	TreeNode *node2 = new TreeNode(3);
	TreeNode *node3 = new TreeNode(4);
	TreeNode *node4 = new TreeNode(5);
	TreeNode *node5 = new TreeNode(6);
	TreeNode *node6 = new TreeNode(7);
	TreeNode *node7 = new TreeNode(8);

	root->left = node1;
	root->right = node2;

	node2->left = node3;
	node2->right = node4;

	node4->left = node5;

	node5->left = node6;
	node5->right = node7;


	Solution s;
	
	cout << s.sumOfLeftLeaves(root)<<endl;

	return 0;
}