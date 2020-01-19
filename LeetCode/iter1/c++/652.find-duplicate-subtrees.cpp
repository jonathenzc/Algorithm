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
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		unordered_map<string, vector<TreeNode*>> map;
		serialize(root, map);
		vector<TreeNode*> ret;
		for (auto iter : map) {
			if (iter.second.size() > 1) {
				ret.push_back(iter.second[0]);
			}
		}
		return ret;
	}
private:
	string serialize(TreeNode* root, unordered_map<string, vector<TreeNode*>>& map) {
		if (root == nullptr) {
			return "#";
		}

		string serializeStr = to_string(root->val) + serialize(root->left, map) + serialize(root->right, map);
		if (map.count(serializeStr) == 1) {
			map[serializeStr].push_back(root);
		}
		else {
			vector<TreeNode*> v(1, root);
			map[serializeStr] = v;
		}

		return serializeStr;
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
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t5 = new TreeNode(2);
	TreeNode* t6 = new TreeNode(4);
	TreeNode* t7 = new TreeNode(4);

	t5->left = t6;

	t3->left = t5;
	t3->right = t7;

	t2->left = t4;

	t1->left = t2;
	t1->right = t3;

	Solution s;
	vector<TreeNode*> v = s.findDuplicateSubtrees(t1);
	for (TreeNode* node : v) {
		testPrint(node);
		cout << endl;
		cout << endl;
	}
}

int main(void)
{
	testCase1();
	cout << endl;

	return 0;
}