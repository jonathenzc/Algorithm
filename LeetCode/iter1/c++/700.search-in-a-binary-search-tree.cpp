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
	TreeNode* searchBST(TreeNode* root, int val) {
		if (root == NULL) {
			return NULL;
		}

		if (val == root->val) {
			return root;
		}
		else if (val < root->val) {
			return searchBST(root->left, val);
		}
		else {
			return searchBST(root->right, val);
		}
	}
};

void testPrint(TreeNode* root) {
	if (root == NULL) return;

	int curLevel = 1;
	queue<pair<TreeNode*, int>> q;
	q.push(pair<TreeNode*, int>(root, curLevel));
	while (!q.empty()) {
		pair<TreeNode*, int> tmpPair = q.front();
		q.pop();

		if (tmpPair.first == NULL) continue;

		q.push(pair<TreeNode*, int>(tmpPair.first->left, tmpPair.second + 1));
		q.push(pair<TreeNode*, int>(tmpPair.first->right, tmpPair.second + 1));
		if (curLevel != tmpPair.second) {
			curLevel = tmpPair.second;
			cout << endl;
		}
		cout << tmpPair.first->val << " ";
	}

}

int main()
{
	TreeNode* root = new TreeNode(4);
	TreeNode* node1 = new TreeNode(2);
	TreeNode* node2 = new TreeNode(1);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(7);

	node1->left = node2;
	node1->right = node3;

	root->left = node1;
	root->right = node4;

	Solution s;
	for (int i = 0; i < 11; i++) {
		cout << "find " << i << endl;
		testPrint(s.searchBST(root, i));
		cout << endl;
	}

	return 0;
}