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
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool findTarget(TreeNode* root, int k) {
		//前序构建容器
		preOrder(root);

		bool ret = false;
		for (int i = 0; i < v.size(); i++) {
			int occurranceCnt = occurrance[k - v[i]];

			if (k-v[i] == v[i]) {
				if (occurranceCnt > 1) {
					ret = true;
					break;
				}
			} else {
				if (occurranceCnt == 1) {
					ret = true;
					break;
				}
			}
		}

		return ret;
	}
private:
	unordered_map<int, int> occurrance;
	vector<int> v;

	void preOrder(TreeNode* root) {
		if (root != NULL) {
			preOrder(root->left);
			occurrance[root->val]++;
			v.push_back(root->val);
			preOrder(root->right);
		}
	}
};

void testPrint(TreeNode *root, int v) {
	Solution s;
	if (s.findTarget(root, v)) {
		cout << v << " find\n";
	} else {
		cout << v << " not find\n";
	}
}

int main(void)
{
	TreeNode *root = new TreeNode(5);
	TreeNode *node1 = new TreeNode(3);
	TreeNode *node2 = new TreeNode(6);
	TreeNode *node3 = new TreeNode(2);
	TreeNode *node4 = new TreeNode(4);
	TreeNode *node5 = new TreeNode(7);

	root->left = node1;
	root->right = node2;

	node1->left = node3;
	node1->right = node4;

	node2->right = node5;

	Solution s;
	testPrint(root, 4);
	testPrint(root, 7);
	testPrint(root, 9);
	testPrint(root, 6);
	testPrint(root, 5);
	testPrint(root, 27);


	return 0;
}