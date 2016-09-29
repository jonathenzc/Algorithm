#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == NULL)
			return v;

		queue<TreeNode*> treeQ;
		queue<int> levelQ;

		treeQ.push(root);
		levelQ.push(1);
		vector<int> curV;

		int curLevel = 1;

		while (!treeQ.empty())
		{
			TreeNode *topNode = treeQ.front();
			treeQ.pop();

			int topLevel = levelQ.front();
			levelQ.pop();

			if (topNode->left != NULL) {
				treeQ.push(topNode->left);
				levelQ.push(topLevel + 1);
			}

			if (topNode->right != NULL) {
				treeQ.push(topNode->right);
				levelQ.push(topLevel + 1);
			}

			if (curLevel == topLevel)
				curV.push_back(topNode->val);
			else {
				v.push_back(curV);
				curLevel = topLevel;
				curV.clear();

				curV.push_back(topNode->val);
			}
		}

		v.push_back(curV);

		return v;
	}

private:

	vector<vector<int>> v;

};

int main()
{
	Solution s;

	TreeNode *root = new TreeNode(3);
	TreeNode *node1 = new TreeNode(9);
	TreeNode *node2 = new TreeNode(20);
	TreeNode *node3 = new TreeNode(15);
	TreeNode *node4 = new TreeNode(7);

	root->left = node1;
	root->right = node2;

	node2->left = node3;
	node2->right = node4;

	auto retV = s.levelOrder(root);

	for (auto innerV : retV)
	{
		for (auto num : innerV)
			cout << num << " ";

		cout << endl;
	}

	return 1;

}