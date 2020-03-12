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
	int longestUnivaluePath(TreeNode* root) {
		longestPath = 0;

		getChildLongestVal(root);

		return longestPath;
	}
private:
	int longestPath;

	int getChildLongestVal(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}

		int leftVal = getChildLongestVal(root->left);
		int rightVal = getChildLongestVal(root->right);

		leftVal = (root->left && root->left->val == root->val) ? leftVal + 1 : 0;
		rightVal = (root->right && root->right->val == root->val) ? rightVal + 1 : 0;

		longestPath = max(longestPath, leftVal + rightVal);
		return max(leftVal, rightVal);
	}
};

void testPrint(TreeNode* treeNode) {
	queue<pair<TreeNode*, int>> treeQ;
	treeQ.push(pair<TreeNode*, int>(treeNode, 1));
	int curLv = 1;

	while (!treeQ.empty()) {
		pair<TreeNode*, int>tmpPair = treeQ.front();
		treeQ.pop();

		if (curLv != tmpPair.second) {
			curLv = tmpPair.second;
			cout << endl;
		}

		cout << tmpPair.first->val << " ";
		if (tmpPair.first->left != NULL) {
			treeQ.push(pair<TreeNode*, int>(tmpPair.first->left, tmpPair.second + 1));
		}
		if (tmpPair.first->right != NULL) {
			treeQ.push(pair<TreeNode*, int>(tmpPair.first->right, tmpPair.second + 1));
		}
	}
}

void testCase1() {
	TreeNode* node1 = new TreeNode(5);
	TreeNode* node2 = new TreeNode(4);
	TreeNode* node3 = new TreeNode(5);
	TreeNode* node4 = new TreeNode(1);
	TreeNode* node5 = new TreeNode(1);
	TreeNode* node6 = new TreeNode(5);

	node2->left = node4;
	node2->right = node5;

	node3->right = node6;

	node1->left = node2;
	node1->right = node3;

	testPrint(node1);
	cout << endl;

	Solution s;
	cout << s.longestUnivaluePath(node1) << endl;
}

void testCase2() {
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(4);
	TreeNode* node3 = new TreeNode(5);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(4);
	TreeNode* node6 = new TreeNode(5);

	node2->left = node4;
	node2->right = node5;

	node3->right = node6;

	node1->left = node2;
	node1->right = node3;

	testPrint(node1);
	cout << endl;

	Solution s;
	cout << s.longestUnivaluePath(node1) << endl;
}

int main(void)
{
	testCase1();
	cout << endl;
	testCase2();
	cout << endl;

	return 0;
}
