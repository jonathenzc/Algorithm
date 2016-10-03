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

	int maxPathSum(TreeNode* root) {
		if (root == NULL)
			return 0;

		candidateSum = INT_MIN;

		if (root->left == NULL && root->right == NULL)
			return root->val;

		int leftSum = helper(root->left);
		int rightSum = helper(root->right);

		int maxSum = max(root->val,leftSum);
		maxSum = max(maxSum,rightSum);
		maxSum = max(maxSum, rightSum+root->val);
		maxSum = max(maxSum, leftSum+root->val);
		maxSum = max(maxSum, root->val + leftSum + rightSum);

		candidateSum = max(candidateSum, maxSum);

		return candidateSum;
	}

private:
	int candidateSum;

	int helper(TreeNode *root)
	{
		if (root == NULL)
			return INT_MIN/4;

		int leftSum = helper(root->left);
		int rightSum = helper(root->right);

		candidateSum = max(candidateSum, rightSum);
		candidateSum = max(candidateSum, leftSum);
		candidateSum = max(candidateSum, root->val);
		candidateSum = max(candidateSum, rightSum+root->val);
		candidateSum = max(candidateSum, leftSum+root->val);
		candidateSum = max(candidateSum, root->val+leftSum+rightSum);

		int maxSum = max(leftSum, rightSum ) + root->val;
		maxSum = max(maxSum,root->val);


		return maxSum ;
	}
};

int main()
{
	TreeNode *root = new TreeNode(1);
	TreeNode *node1 = new TreeNode(-2);
	TreeNode *node2 = new TreeNode(-3);
	TreeNode *node3 = new TreeNode(1);
	TreeNode *node4 = new TreeNode(3);
	TreeNode *node5 = new TreeNode(-2);
	TreeNode *node6 = new TreeNode(-1);

	root->left = node1;
	root->right = node2;

	node1->left = node3;
	node1->right = node4;

	node3->left = node6;

	node2->left = node5;

	Solution s;

	cout<<s.maxPathSum(root);


	return 0;
}