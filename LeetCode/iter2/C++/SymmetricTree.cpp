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
	//迭代版本
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;
		
		return helper(root->left,root->right);
	}

	//递归版本
	bool isSymmetricIter(TreeNode* root) {
		vector<TreeNode*> st;
		if (root == NULL)
			return true;

		st.push_back(root->left);
		st.push_back(root->right);

		while (!st.empty())
		{
			TreeNode *rightNode = st.back();
			st.pop_back();

			TreeNode *leftNode = st.back();
			st.pop_back();

			if (rightNode != NULL && leftNode != NULL)
			{
				if (rightNode->val == leftNode->val)
				{
					st.push_back(leftNode->left);
					st.push_back(rightNode->right);

					st.push_back(leftNode->right);
					st.push_back(rightNode->left);
				}
				else
					return false;
			}
			else if (rightNode == NULL && leftNode == NULL)
			{
			}
			else
				return false;
		}

		return true;
	}
private:
	bool helper(TreeNode *left, TreeNode *right)
	{
		if (left != NULL && right != NULL)
		{
			if (left->val == right->val)
				return helper(left->left, right->right) && helper(left->right, right->left);
			else
				return false;
		}
		else if (left == NULL && right == NULL)
			return true;
		else
			return false;
	}
};

int main()
{
	TreeNode *root = new TreeNode(1);
	TreeNode *L2 = new TreeNode(2);
	TreeNode *R2 = new TreeNode(2);
	TreeNode *LL = new TreeNode(3);
	TreeNode *LR = new TreeNode(4);
	TreeNode *RL = new TreeNode(4);
	TreeNode *RR = new TreeNode(3);

	root->left = L2;
	root->right = R2;

	L2->left = LL;
	L2->right = LR;

	R2->left = RL;
	R2->right = RR;

	Solution s;

	bool isSymmetric = s.isSymmetricIter(root);
	
	if (isSymmetric)
		cout << "Yes\n";
	else
		cout << "No\n";

	return 0;
}