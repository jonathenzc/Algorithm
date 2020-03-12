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
	int getMinimumDifference(TreeNode* root) {
		if (root == nullptr) return INT_MAX;

		int leftMax = INT_MAX;
		if (root->left != nullptr) {
			leftMax = findMaxVal(root->left);
		}

		int rightMin = INT_MAX;
		if (root->right != nullptr) {
			rightMin = findMinVal(root->right);
		}

		int curMin = INT_MAX;
		if (leftMax != INT_MAX) {
			curMin = abs(root->val - leftMax);
		}

		if (rightMin != INT_MAX) {
			curMin = min(curMin, abs(root->val - rightMin));
		}

		return min(min(curMin, getMinimumDifference(root->left)), getMinimumDifference(root->right));
	}
private:
	int findMaxVal(TreeNode* root) {
		int ret = INT_MAX;
		while (root) {
			ret = root->val;
			root = root->right;
		}
		return ret;
	}

	int findMinVal(TreeNode* root) {
		int ret = INT_MAX;
		while (root) {
			ret = root->val;
			root = root->left;
		}
		return ret;
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
	TreeNode* t2 = new TreeNode(3);
	TreeNode* t3 = new TreeNode(2);
	TreeNode* t4 = new TreeNode(5);
	TreeNode* t5 = new TreeNode(3);
	TreeNode* t6 = new TreeNode(9);

	t2->left = t4;
	t2->right = t5;

	t3->right = t6;

	t1->left = t2;
	t1->right = t3;

	testPrint(t1);
	cout << endl;

	Solution s;
	cout << s.getMinimumDifference(t1) << endl;
}

void testCase2() {
	TreeNode* t1 = new TreeNode(5);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(10);
	TreeNode* t4 = new TreeNode(9);
	TreeNode* t5 = new TreeNode(4);
	TreeNode* t6 = new TreeNode(13);

	t2->left = t4;
	t2->right = t5;

	t3->right = t6;

	t1->left = t2;
	t1->right = t3;

	testPrint(t1);
	cout << endl;

	Solution s;
	cout << s.getMinimumDifference(t1) << endl;
}

void testCase3() {
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(5);
	TreeNode* t3 = new TreeNode(3);

	t2->left = t3;
	t1->right = t2;

	testPrint(t1);
	cout << endl;

	Solution s;
	cout << s.getMinimumDifference(t1) << endl;
}

//[236,104,701,null,227,null,911]
//       236
//   104     701
//      227     911
void testCase4() {
	TreeNode* t1 = new TreeNode(236);
	TreeNode* t2 = new TreeNode(104);
	TreeNode* t3 = new TreeNode(701);
	TreeNode* t4 = new TreeNode(227);
	TreeNode* t5 = new TreeNode(911);

	t2->right = t4;
	t3->right = t5;

	t1->left = t2;
	t1->right = t3;

	testPrint(t1);
	cout << endl;

	Solution s;
	cout << s.getMinimumDifference(t1) << endl;
}

int main(void)
{
	testCase1();
	cout << endl;
	testCase2();
	cout << endl;
	testCase3();
	cout << endl;
	testCase4();

	return 0;
}