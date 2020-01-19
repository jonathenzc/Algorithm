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
	int widthOfBinaryTree(TreeNode* root) {
		if (root == nullptr) return 0;

		queue<TreeNode*> treeNQ;
		root->val = 1;
		treeNQ.push(root);

		int ret = 1;

		while (!treeNQ.empty()) {
			int thisLvWidth = treeNQ.size();
			if (thisLvWidth == 1) {
				treeNQ.front()->val = 1;
				treeNQ.push(treeNQ.front());
				treeNQ.pop();
			}
			ret = max({ ret,treeNQ.back()->val - treeNQ.front()->val + 1 });

			for (int i = 0; i < thisLvWidth; i++) {
				TreeNode* treeNode = treeNQ.front();
				treeNQ.pop();

				if (treeNode->left != nullptr) {
					treeNode->left->val = 2 * treeNode->val;
					treeNQ.push(treeNode->left);
				}

				if (treeNode->right != nullptr) {
					treeNode->right->val = 2 * treeNode->val + 1;
					treeNQ.push(treeNode->right);
				}
			}
		}
		return ret;
	}

	int widthOfBinaryTree1(TreeNode* root) {
		if (!root) return 0;
		queue<pair<TreeNode*, int> > q;
		q.push({ root, 1 });
		int ans = 0;
		while (!q.empty()) {
			int size = q.size();
			if (size == 1) {
				q.push({ q.front().first,1 });
				q.pop();
			}
			ans = max(q.back().second - q.front().second + 1, ans);

			while (size-- > 0) {
				auto node = q.front().first;
				auto idx = q.front().second;
				q.pop();
				if (node->left)
					q.push({ node->left, idx * 2 });
				if (node->right)
					q.push({ node->right, idx * 2 + 1 });
			}

		}
		return ans;
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
	TreeNode* t4 = new TreeNode(5);
	TreeNode* t5 = new TreeNode(3);
	TreeNode* t6 = new TreeNode(9);

	t3->left = t4;
	t3->right = t5;

	t2->right = t6;

	t1->left = t3;
	t1->right = t2;

	testPrint(t1);
	cout << endl;

	Solution s;
	cout << s.widthOfBinaryTree(t1) << endl;
}

void testCase2() {
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(3);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(5);

	t2->left = t4;
	t2->right = t3;

	t1->left = t2;

	Solution s;
	cout << s.widthOfBinaryTree(t1) << endl;
}

void testCase3() {
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(5);

	t3->left = t4;

	t1->left = t3;
	t1->right = t2;

	Solution s;
	cout << s.widthOfBinaryTree(t1) << endl;
}

void testCase4() {
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(5);
	TreeNode* t5 = new TreeNode(6);
	TreeNode* t6 = new TreeNode(7);
	TreeNode* t7 = new TreeNode(9);

	t4->left = t5;
	t7->right = t6;

	t3->left = t4;
	t2->right = t7;

	t1->left = t3;
	t1->right = t2;

	Solution s;
	cout << s.widthOfBinaryTree(t1) << endl;
}

int main(void)
{
	testCase1();
	testCase2();
	testCase3();
	testCase4();

	return 0;
}