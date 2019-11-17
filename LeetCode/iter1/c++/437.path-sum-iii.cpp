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
	int pathSum(TreeNode* root, int sum) {
		if (root == NULL) {
			return 0;
		}

		return pathSumBeginFromRoot(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
	}
private:
	int pathSumBeginFromRoot(TreeNode* root, int target) {
		if (root == NULL) {
			return 0;
		}

		return (root->val == target ? 1 : 0) + pathSumBeginFromRoot(root->left, target - root->val) + pathSumBeginFromRoot(root->right, target - root->val);
	}
};

void printV(vector<double> v) {
	for (double num : v) {
		cout << num << " ";
	}
}

int main()
{
	TreeNode* node1 = new TreeNode(10);
	TreeNode* node2 = new TreeNode(5);
	TreeNode* node3 = new TreeNode(-3);
	TreeNode* node4 = new TreeNode(3);
	TreeNode* node5 = new TreeNode(2);
	TreeNode* node6 = new TreeNode(11);
	TreeNode* node7 = new TreeNode(3);
	TreeNode* node8 = new TreeNode(-2);
	TreeNode* node9 = new TreeNode(1);

	node4->left = node7;
	node4->right = node8;
	node5->right = node9;
	node2->left = node4;
	node2->right = node5;
	node3->right = node6;
	node1->left = node2;
	node1->right = node3;

	Solution s;
	cout << s.pathSum(node1, 8) << endl;

	return 0;
}