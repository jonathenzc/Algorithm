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
	TreeNode* deleteNode(TreeNode* root, int key) {
		TreeNode* originNode = root;

		//找出目标节点
		TreeNode* parentNode = nullptr;
		while (root != nullptr && root->val != key) {
			parentNode = root;
			if (root->val < key) {
				root = root->right;
			}
			else if (root->val > key) {
				root = root->left;
			}
		}
		//若找到节点边重构bst
		if (parentNode == nullptr) {
			return deleteCurNode(root);
		}

		if (root == parentNode->left) {
			parentNode->left = deleteCurNode(root);
		}
		else if (root == parentNode->right) {
			parentNode->right = deleteCurNode(root);
		}

		return originNode;
	}
private:
	TreeNode* deleteCurNode(TreeNode* root) {
		if (root == nullptr) return root;
		if (root->left == nullptr) return root->right;
		if (root->right == nullptr) return root->left;

		//找到root右子树的最左边
		TreeNode* rightLeftestNode = root->right, * preNode = root;
		while (rightLeftestNode->left != nullptr) {
			preNode = rightLeftestNode;
			rightLeftestNode = rightLeftestNode->left;
		}

		rightLeftestNode->left = root->left;
		if (rightLeftestNode != root->right) {
			preNode->left = rightLeftestNode->right;
			rightLeftestNode->right = root->right;
		}
		return rightLeftestNode;
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
	TreeNode* ret = s.deleteNode(t1, 3);
	testPrint(ret);
}

int main(void)
{
	testCase1();

	return 0;
}