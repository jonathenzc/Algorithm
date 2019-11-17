#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int diameterOfBinaryTree(TreeNode* root) {
		if (root == NULL) return 0;

		diameter = 0;
		getTreeDepth(root);

		return diameter - 1;
	}
private:
	int diameter;

	int getTreeDepth(TreeNode* root) {
		if (root == NULL) return 0;

		int LDepth = getTreeDepth(root->left);
		int RDepth = getTreeDepth(root->right);

		diameter = max(diameter, LDepth + RDepth + 1);

		return max(LDepth, RDepth) + 1;
	}
};

TreeNode* testCase1() {
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);

	node2->left = node4;
	node2->right = node5;

	node1->left = node2;
	node1->right = node5;

	return node1;
}

TreeNode* testCase2() {
	//	1
	//2     3
	//4 5
	//6   7
	//8    9
	//      10
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);
	TreeNode* node6 = new TreeNode(6);
	TreeNode* node7 = new TreeNode(7);
	TreeNode* node8 = new TreeNode(8);
	TreeNode* node9 = new TreeNode(9);
	TreeNode* node10 = new TreeNode(10);

	node9->left = node10;
	node7->right = node9;
	node5->right = node7;

	node6->right = node8;
	node4->left = node6;

	node2->left = node4;
	node2->right = node5;

	node1->left = node2;
	node1->right = node3;

	return node1;
}

int main()
{
	Solution solution;
	cout << solution.diameterOfBinaryTree(testCase1()) << endl;
	cout << solution.diameterOfBinaryTree(testCase2()) << endl;

	return 0;
}