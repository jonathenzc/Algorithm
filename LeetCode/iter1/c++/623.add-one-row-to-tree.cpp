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
	TreeNode* addOneRow(TreeNode* root, int v, int d) {
		if (d == 1) {
			TreeNode* tmp = new TreeNode(v);
			tmp->left = root;
			root = tmp;
			return root;
		}

		queue<pair<TreeNode*, int>> treeNodeQ;
		treeNodeQ.push(pair<TreeNode*, int>(root, 1));

		//locate level
		vector<TreeNode*> parentsV;
		while (!treeNodeQ.empty()) {
			pair<TreeNode*, int> nodePair = treeNodeQ.front();
			treeNodeQ.pop();
			if (nodePair.second == d - 1) {
				parentsV.push_back(nodePair.first);
			}
			else {
				if (nodePair.first->left != NULL) {
					treeNodeQ.push(pair<TreeNode*, int>(nodePair.first->left, nodePair.second + 1));
				}
				if (nodePair.first->right != NULL) {
					treeNodeQ.push(pair<TreeNode*, int>(nodePair.first->right, nodePair.second + 1));
				}
			}
		}

		//change parent and children
		for (int i = 0; i < parentsV.size(); i++) {
			TreeNode* leftAddedNode = new TreeNode(v);
			leftAddedNode->left = parentsV[i]->left;
			parentsV[i]->left = leftAddedNode;

			TreeNode* rightAddedNode = new TreeNode(v);
			rightAddedNode->right = parentsV[i]->right;
			parentsV[i]->right = rightAddedNode;
		}

		return root;
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
	t1->left = t2;

	Solution s;
	testPrint(s.addOneRow(t1, 100, 1));
	cout << endl;
}

void testCase2() {
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t5 = new TreeNode(5);
	TreeNode* t6 = new TreeNode(6);

	t2->left = t3;
	t2->right = t1;

	t6->left = t5;

	t4->left = t2;
	t4->right = t6;

	Solution s;
	testPrint(s.addOneRow(t4, 1, 2));
	cout << endl;
}

void testCase3() {
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);

	t2->left = t3;
	t2->right = t1;
	t2->left = t3;

	t4->left = t2;

	Solution s;
	testPrint(s.addOneRow(t4, 1, 3));
	cout << endl;
}

int main(void)
{
	testCase1();
	cout << endl;
	testCase2();
	cout << endl;
	testCase3();

	return 0;
}