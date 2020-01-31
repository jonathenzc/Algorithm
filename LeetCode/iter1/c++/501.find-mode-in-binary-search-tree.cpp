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
	vector<int> findMode(TreeNode* root) {
		max = 0, cur = 0, preNode = nullptr;
		inorderHelper(root);

		return ret;
	}
private:
	vector<int> ret;
	int max;
	int cur;
	TreeNode* preNode;

	void inorderHelper(TreeNode* root) {
		if (root == nullptr) {
			return;
		}

		inorderHelper(root->left);

		if (preNode == nullptr) {
			cur = 1;
		}
		else {
			preNode->val == root->val ? cur++ : cur = 1;
		}

		if (cur == max) {
			ret.push_back(root->val);
		}
		else if (cur > max) {
			max = cur;
			ret.clear();
			ret.push_back(root->val);
		}

		preNode = root;
		inorderHelper(root->right);
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
	TreeNode* t2 = new TreeNode(3);
	TreeNode* t3 = new TreeNode(6);
	TreeNode* t4 = new TreeNode(2);
	TreeNode* t5 = new TreeNode(4);
	TreeNode* t6 = new TreeNode(7);

	t2->left = t4;
	t2->right = t5;

	t3->right = t6;

	t1->left = t2;
	t1->right = t3;

	testPrint(t1);
	cout << endl;

	Solution s;
	vector<int> ret = s.findMode(t1);
	for (int num : ret) {
		cout << num << " ";
	}
	cout << endl;
}

void testCase2() {
	TreeNode* t1 = new TreeNode(5);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(6);
	TreeNode* t4 = new TreeNode(2);
	TreeNode* t5 = new TreeNode(4);
	TreeNode* t6 = new TreeNode(7);

	t2->left = t4;
	t2->right = t5;

	t3->right = t6;

	t1->left = t2;
	t1->right = t3;

	testPrint(t1);
	cout << endl;

	Solution s;
	vector<int> ret = s.findMode(t1);
	for (int num : ret) {
		cout << num << " ";
	}
	cout << endl;
}

int main(void)
{
	testCase1();
	cout << endl;
	testCase2();

	return 0;
}