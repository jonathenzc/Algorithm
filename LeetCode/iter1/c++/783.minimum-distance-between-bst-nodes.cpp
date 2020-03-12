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
	int minDiffInBST(TreeNode* root) {
		minDiff = INT_MAX, preNum = INT_MIN;
		inorderHelper(root);
		return minDiff;
	}

private:
	int minDiff;
	int preNum;

	void inorderHelper(TreeNode* root) {
		if (root->left) {
			inorderHelper(root->left);
		}

		if (preNum != INT_MIN) {
			minDiff = min(minDiff, abs(root->val - preNum));
		}

		preNum = root->val;

		if (root->right) {
			inorderHelper(root->right);
		}
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
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t5 = new TreeNode(6);

	t2->left = t1;
	t2->right = t3;

	t4->left = t2;
	t4->right = t5;

	Solution s;
	cout << s.minDiffInBST(t4) << endl;
}

//[90,69,null,49,89,null,52,null,null,null,null]
//    90
//  69
// 49 89
//  52
void testCase2() {
	TreeNode* t1 = new TreeNode(90);
	TreeNode* t2 = new TreeNode(69);
	TreeNode* t3 = new TreeNode(49);
	TreeNode* t4 = new TreeNode(89);
	TreeNode* t5 = new TreeNode(52);

	t3->right = t5;

	t2->left = t3;
	t2->right = t4;

	t1->left = t2;

	Solution s;
	cout << s.minDiffInBST(t1) << endl;
}

int main(void)
{
	testCase1();
	cout << endl;
	testCase2();
	cout << endl;

	return 0;
}
