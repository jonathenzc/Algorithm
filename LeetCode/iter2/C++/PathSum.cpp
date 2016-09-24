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
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return false;

		isFound = false;

		helper(root, 0,sum);

		return isFound;
	}
private:
	bool isFound;

	void helper(TreeNode *node, int cur, int target)
	{
		if (node->left == NULL && node->right == NULL) //叶子节点
		{
			if (target == cur + node->val)
				isFound = true;
			else
				isFound = false;
		}
		else
		{
			if (!isFound && node->left != NULL) //right是空
				helper(node->left, node->val + cur, target);
		
			if (!isFound && node->right != NULL)
				helper(node->right, node->val + cur, target);
		}
		
	}
};

int main()
{
	TreeNode *root = new TreeNode(5);
	TreeNode *node1 = new TreeNode(4);
	TreeNode *node2 = new TreeNode(8);
	TreeNode *node3 = new TreeNode(11);
	TreeNode *node4 = new TreeNode(13);
	TreeNode *node5 = new TreeNode(4);
	TreeNode *node6 = new TreeNode(7);
	TreeNode *node7 = new TreeNode(2);
	TreeNode *node8 = new TreeNode(5);
	TreeNode *node9 = new TreeNode(1);

	root->left = node1;
	root->right = node2;

	node1->left = node3;

	node2->left = node4;
	node2->right = node5;

	node3->left = node6;
	node3->right = node7;

	node5->left = node8;
	node5->right = node9;


	//TreeNode *root = new TreeNode(1);
	//TreeNode *node1 = new TreeNode(2);

	//root->left = node1;

	Solution s;

	bool isSymmetric = s.hasPathSum(root,23);
	
	if (isSymmetric)
		cout << "Yes\n";
	else
		cout << "No\n";

	return 0;
}