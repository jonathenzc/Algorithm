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
	vector<vector<string>> printTree(TreeNode* root) {
		if (root == NULL) {
			vector<vector<string>> retV;
			return retV;
		}

		int height = getHeight(root);
		int col = pow(2, height) - 1;
		vector<vector<string>> retV(height, vector<string>(col, ""));

		queue<pair<TreeNode*, int>> treeNodeQ;
		queue<pair<int, int>> posQ;
		treeNodeQ.push(pair<TreeNode*, int>(root, 0));
		posQ.push(pair<int, int>(0, col - 1));

		while (!treeNodeQ.empty()) {
			pair<TreeNode*, int> node = treeNodeQ.front();
			treeNodeQ.pop();

			pair<int, int> tmpPos = posQ.front();
			posQ.pop();

			int midPos = tmpPos.first + (tmpPos.second - tmpPos.first) / 2;
			retV[node.second][midPos] = to_string(node.first->val);

			if (node.first->left != NULL) {
				treeNodeQ.push(pair<TreeNode*, int>(node.first->left, node.second + 1));
				posQ.push(pair<int, int>(tmpPos.first, midPos - 1));
			}

			if (node.first->right != NULL) {
				treeNodeQ.push(pair<TreeNode*, int>(node.first->right, node.second + 1));
				posQ.push(pair<int, int>(midPos + 1, tmpPos.second));
			}
		}

		return retV;
	}

private:
	int getHeight(TreeNode* root) {
		if (root == NULL) return 0;
		return max(getHeight(root->left), getHeight(root->right)) + 1;
	}
};

void testPrint(vector<vector<string>> v) {
	for (int i = 0; i < v.size(); i++) {
		string s = "[";
		for (int j = 0; j < v[i].size(); j++) {
			s += "\"" + v[i][j] + "\"" + ", ";
		}
		cout << s.substr(0, s.size() - 2) << "]\n";
	}
}

void testCase1() {
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	t1->left = t2;

	Solution s;
	testPrint(s.printTree(t1));
}

void testCase2() {
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);
	t2->right = t4;
	t1->left = t2;
	t1->right = t3;

	Solution s;
	testPrint(s.printTree(t1));
}

void testCase3() {
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t5 = new TreeNode(5);
	TreeNode* t6 = new TreeNode(6);

	t3->left = t4;
	t3->right = t6;
	t2->left = t3;

	t1->left = t2;
	t1->right = t5;

	Solution s;
	testPrint(s.printTree(t1));
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