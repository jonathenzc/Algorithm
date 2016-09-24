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

	vector<string> binaryTreePaths(TreeNode* root) {
		if (root == NULL)
			return v;

		string littleV="";

		helper(root, littleV);

		return v;
	}

private:
	vector<string > v;

	void helper(TreeNode *node, string curV)
	{
		if (node->left == NULL && node->right == NULL) //叶子节点
		{
				stringstream ss;
				ss << node->val;
				string nodeStr;
				ss >> nodeStr;

				curV = curV + nodeStr;
				v.push_back(curV);
		}
		else
		{
			stringstream ss;
			ss << node->val;
			string nodeStr;
			ss >> nodeStr;
			string newStr = curV + nodeStr + "->";

			if (node->left != NULL) //right是空
				helper(node->left, newStr);
		
			if (node->right != NULL) 
				helper(node->right, newStr);
		}
		
	}
};

int main()
{
	TreeNode *root = new TreeNode(5);
	TreeNode *node1 = new TreeNode(4);
	TreeNode *node2 = new TreeNode(8);
	TreeNode *node3 = new TreeNode(11);
	TreeNode *node4 = new TreeNode(13);
	TreeNode *node5 = new TreeNode(4);
	TreeNode *node6 = new TreeNode(7);
	TreeNode *node7 = new TreeNode(2);
	TreeNode *node8 = new TreeNode(5);
	TreeNode *node9 = new TreeNode(1);

	root->left = node1;
	root->right = node2;

	node1->left = node3;

	node2->left = node4;
	node2->right = node5;

	node3->left = node6;
	node3->right = node7;

	node5->left = node8;
	node5->right = node9;

	Solution s;

	vector<string> v = s.binaryTreePaths(root);
	for (string str : v)
		cout << str << endl;

	return 0;
}