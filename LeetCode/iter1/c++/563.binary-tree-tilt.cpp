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
	int findTilt(TreeNode* root) {
		int allNodeTiltSum = 0;

		getChildrenTilt(root, allNodeTiltSum);

		return allNodeTiltSum;
	}
private:
	int getChildrenTilt(TreeNode* root, int& tiltSum) {
		if (root == nullptr) {
			return 0;
		}

		int leftTiltSum = getChildrenTilt(root->left, tiltSum) + (root->left ? root->left->val : 0);
		int rightTiltSum = getChildrenTilt(root->right, tiltSum) + (root->right ? root->right->val : 0);

		tiltSum += abs(leftTiltSum - rightTiltSum);

		return leftTiltSum + rightTiltSum;
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
	cout << s.findTilt(t1) << endl;
}

void testCase2() {
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);

	t1->left = t2;
	t1->right = t3;

	testPrint(t1);
	cout << endl;

	Solution s;
	cout << s.findTilt(t1) << endl;
}

//[1,2,null,3,4]
void testCase3() {
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);

	t2->left = t3;
	t2->right = t4;

	t1->left = t2;

	testPrint(t1);
	cout << endl;

	Solution s;
	cout << s.findTilt(t1) << endl;
}

int main(void)
{
	testCase1();
	cout << endl;
	testCase2();
	cout << endl;
	testCase3();
	cout << endl;

	return 0;
}
