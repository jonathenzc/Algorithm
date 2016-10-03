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

	vector<int> preorderTraversalIter(TreeNode* root) {

		if (root != NULL)
		{
			st.push_back(root);

			while (!st.empty())
			{
				TreeNode *topNode = st.back();
				st.pop_back();

				if (topNode != NULL)
					v.push_back(topNode->val);

				if (topNode->right != NULL)
					st.push_back(topNode->right);

				if (topNode->left != NULL)
					st.push_back(topNode->left);
			}
		}

		return v;
	}

	vector<int> preorderTraversal(TreeNode* root) {

		helper(root);

		return v;
	}

private:
	vector<int> v;

	vector<TreeNode*> st;

	void helper(TreeNode *root)
	{
		if (root != NULL)
		{
			v.push_back(root->val);
			helper(root->left);
			helper(root->right);
		}
	}
};

int main()
{
	TreeNode *root = new TreeNode(1);
	TreeNode *node1 = new TreeNode(2);
	TreeNode *node2 = new TreeNode(3);

	root->right = node1;
	node1->left = node2;

	Solution s;

	vector<int> v = s.preorderTraversalIter(root);

	for (int num : v)
		cout << num << " ";

	return 0;
}