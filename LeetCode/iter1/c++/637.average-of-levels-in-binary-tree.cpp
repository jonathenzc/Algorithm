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
	vector<double> averageOfLevels(TreeNode* root) {
		if (root == NULL) {
			vector<double> v;
			v.push_back(0);
			return v;
		}

		queue<pair<TreeNode*, int>> q;
		q.push(pair<TreeNode*, int>(root, 0));

		vector<double> ret;
		double valSum = 0;
		int sameLevelCnt = 0;
		int curLevel = 0;
		while (!q.empty()) {
			pair<TreeNode*, int> tmpNode = q.front();
			q.pop();
			if (tmpNode.second != curLevel) {
				ret.push_back(valSum / sameLevelCnt);

				curLevel++;
				valSum = 0;
				sameLevelCnt = 0;
			}

			valSum += tmpNode.first->val;
			sameLevelCnt++;
			if (tmpNode.first->left != NULL) {
				q.push(pair<TreeNode*, int>(tmpNode.first->left, curLevel + 1));
			}

			if (tmpNode.first->right != NULL) {
				q.push(pair<TreeNode*, int>(tmpNode.first->right, curLevel + 1));
			}
		}

		ret.push_back(valSum / sameLevelCnt);
		return ret;
	}
};

void printV(vector<double> v) {
	for (double num : v) {
		cout << num << " ";
	}
}

int main()
{
	TreeNode *node3 = new TreeNode(3);
	TreeNode *node9 = new TreeNode(9);
	TreeNode *node20 = new TreeNode(20);
	TreeNode *node15 = new TreeNode(15);
	TreeNode *node7 = new TreeNode(7);

	node20->left = node15;
	node20->right = node7;

	node3->left = node9;
	node3->right = node20;

	Solution s;
	printV(s.averageOfLevels(node3));

	return 0;
}