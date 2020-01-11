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
	int findBottomLeftValue(TreeNode* root) {
		queue<pair<TreeNode*, int>> q;
		q.push(pair<TreeNode*, int>(root, 1));

		int ret = -1;
		int curLevel = 0;
		while (!q.empty()) {
			pair<TreeNode*, int> tmpPair = q.front();
			q.pop();
			if (curLevel != tmpPair.second) {
				curLevel = tmpPair.second;
				ret = tmpPair.first->val;
			}

			if (tmpPair.first->left != NULL) {
				q.push(pair<TreeNode*, int>(tmpPair.first->left, curLevel + 1));
			}

			if (tmpPair.first->right != NULL) {
				q.push(pair<TreeNode*, int>(tmpPair.first->right, curLevel + 1));
			}
		}

		return ret;
	}
};

void testPrint(TreeNode* tree) {
	if (tree != NULL) {
		testPrint(tree->left);
		cout << tree->val << endl;
		testPrint(tree->right);
	}
}

void testCase1() {
	TreeNode* t0 = new TreeNode(1);
	TreeNode* t1 = new TreeNode(2);
	TreeNode* t2 = new TreeNode(3);
	TreeNode* t3 = new TreeNode(4);
	TreeNode* t4 = new TreeNode(5);
	TreeNode* t5 = new TreeNode(6);
	TreeNode* t6 = new TreeNode(7);

	t4->left = t6;
	t2->left = t4;
	t2->right = t5;

	t1->left = t3;

	t0->left = t1;
	t0->right = t2;

	Solution s;
	cout << s.findBottomLeftValue(t0) << endl;
}

void testCase2() {
	TreeNode* t0 = new TreeNode(2);
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(3);

	t0->left = t1;
	t0->right = t2;

	Solution s;
	cout << s.findBottomLeftValue(t0) << endl;
}

int main(void)
{
	testCase1();
	testCase2();

	return 0;
}