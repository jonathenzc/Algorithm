#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		inOrderHelper(root);

		return v[k-1];
	}
private:
	vector<int> v;

	void inOrderHelper(TreeNode* root)
	{
		if (root != NULL)
		{
			inOrderHelper(root->left);
			v.push_back(root->val);
			inOrderHelper(root->right);
		}
	}
};