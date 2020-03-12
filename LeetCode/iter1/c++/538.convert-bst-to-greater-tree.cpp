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
	TreeNode* convertBST(TreeNode* root) {
		convertChildBST(root, 0);

		return root;
	}
private:
	int convertChildBST(TreeNode* root, int greaterSum) {
		if (root == nullptr) {
			return 0;
		}

		int originVal = root->val;
		int rightSum = convertChildBST(root->right, greaterSum);
		int leftSum = convertChildBST(root->left, rightSum + originVal + greaterSum);

		//当前节点的值需添加右父亲节点及右子树节点
		root->val += greaterSum + rightSum;

		return originVal + rightSum + leftSum;
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
	TreeNode* t1 = new TreeNode(5);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(13);

	t1->left = t2;
	t1->right = t3;

	testPrint(t1);
	cout << endl;

	Solution s;
	testPrint(s.convertBST(t1));
	cout << endl;
}

void testCase2() {
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t5 = new TreeNode(5);
	TreeNode* t6 = new TreeNode(6);
	TreeNode* t7 = new TreeNode(7);
	TreeNode* t8 = new TreeNode(8);

	t6->left = t5;

	t7->left = t6;
	t7->right = t8;

	t2->left = t1;
	t2->right = t3;

	t4->left = t2;
	t4->right = t7;

	testPrint(t4);
	cout << endl;

	Solution s;
	testPrint(s.convertBST(t4));
	cout << endl;
}

void testCase3() {
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);

	t4->left = t3;
	t3->left = t2;
	t2->left = t1;

	testPrint(t4);
	cout << endl;

	Solution s;
	testPrint(s.convertBST(t4));
	cout << endl;
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
