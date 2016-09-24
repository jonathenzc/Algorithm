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
	//递归版本
	vector<int> inorderTraversal(TreeNode* root) {
		helper(root);

		return v;
	}

	//迭代版本
	vector<int> inorderTraversalIter(TreeNode* root) {
		vector<TreeNode*> st;
		st.push_back(root);

		while (!st.empty())
		{
			TreeNode *node = st.back();
			st.pop_back();

			if (node != NULL)
			{
				if (node->left == NULL && node->right == NULL) //叶子节点
				{
					v.push_back(node->val);
				}
				else
				{
					st.push_back(node->right);
					st.push_back(new TreeNode(node->val));
					st.push_back(node->left);
				}
			}	
		}

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

	vector<int> v = s.inorderTraversalIter(root);

	for (auto num : v)
		cout << num << " ";

	return 0;
}