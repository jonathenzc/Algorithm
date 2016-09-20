#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
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
	vector<int> inorderTraversal(TreeNode* root) {
		helper(root);

		return v;
	}
private:
	vector<int> v;

	void helper(TreeNode *root)
	{
		if (root != NULL)
		{
			helper(root->left);
			v.push_back(root->val);
			helper(root->right);
		}
	}
};

int main()
{
	TreeNode *root = new TreeNode(1);
	TreeNode *left = new TreeNode(2);
	TreeNode *right = new TreeNode(3);

	root->right = left;
	left->left = right;

	Solution s;

	vector<int> v = s.inorderTraversal(root);

	for (auto num : v)
		cout << num << " ";

	return 0;
}