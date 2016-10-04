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

	int sumNumbers(TreeNode* root) {
		sum = 0;

		if (root != NULL)
		{
			string s = "";
			s += char(root->val + '0');

			if(root->left != NULL)
				helper(root->left,s);

			if(root->right != NULL)
				helper(root->right,s);

			if (root->left == NULL && root->right == NULL)
				sum += str2int(s);
		}

		return sum;
	}

private:
	int sum;

	void helper(TreeNode* root, string s)
	{
		if (root->left == NULL  && root->right == NULL)
		{
			string tmpS = s + char(root->val + '0');
			sum += str2int(tmpS);
		}
		else
		{
			string tmpS = s + char(root->val + '0');

			if (root->left != NULL)
				helper(root->left, tmpS);

			if (root->right != NULL)
				helper(root->right, tmpS);
		}
	}

	int str2int(string s)
	{
		stringstream ss;
		ss << s;
		int num;
		ss >> num;

		return num;
	}
};

int main()
{
	TreeNode *root = new TreeNode(1);
	TreeNode *node1 = new TreeNode(2);
	TreeNode *node2 = new TreeNode(3);

	root->left = node1;
	node1->right = node2;

	Solution s;

	cout << s.sumNumbers(root);


	return 0;
}