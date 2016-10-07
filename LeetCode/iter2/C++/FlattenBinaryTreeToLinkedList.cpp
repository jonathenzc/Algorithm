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
	void flatten(TreeNode* root) {
		if (root != NULL)
		{
			TreeNode* rootRight = root->right;

			if (root->left != NULL)
			{
				auto rootLeft = helper(root->left);
				root->right = rootLeft.first;
				rootLeft.second->right = helper(rootRight).first;
				root->left = NULL;
			}
			else
				root->right = helper(rootRight).first;
		}
	}
private:
	vector<int> v;

	pair<TreeNode*,TreeNode*> helper(TreeNode *root)
	{
		if (root == NULL)
			return pair<TreeNode*, TreeNode*>(NULL,NULL);

		if(root->left == NULL && root->right == NULL)
			return pair<TreeNode*, TreeNode*>(root, root);

		pair<TreeNode*, TreeNode*> rootLeft;
		pair<TreeNode*, TreeNode*> rootRight;

		if (root->left != NULL)
		{
			rootLeft = helper(root->left);
			rootRight = helper(root->right);

			root->right = rootLeft.first;
			rootLeft.second->right = rootRight.first;

			root->left = NULL;
		}
		else
		{
			rootRight = helper(root->right);
			root->right = rootRight.first;
		}

		pair<TreeNode*, TreeNode*> retP;
		retP.first = root;

		if (rootLeft.second == NULL && rootRight.second == NULL)
			retP.second = root;
		else if (rootLeft.second != NULL && rootRight.second == NULL)
			retP.second = rootLeft.second;
		else if (rootRight.second != NULL)
			retP.second = rootRight.second;


		return retP;
	}
};