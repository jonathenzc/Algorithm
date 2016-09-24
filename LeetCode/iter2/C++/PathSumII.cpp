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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return v;
		
		vector<int> littleV;

		helper(root, 0, littleV, sum);

		return v;
	}
private:
	vector<vector<int>> v;

	void helper(TreeNode *node, int cur, vector<int> curV, int target)
	{
		if (node->left == NULL && node->right == NULL) //叶子节点
		{
			if (target == cur + node->val)
			{
				curV.push_back(node->val);
				v.push_back(curV);
			}
		}
		else
		{
			if (node->left != NULL) //right是空
			{
				curV.push_back(node->val);
				helper(node->left, node->val + cur, curV,target);
				curV.pop_back();
			}
		
			if (node->right != NULL) 
			{
				curV.push_back(node->val);
				helper(node->right, node->val + cur, curV,target);
				curV.pop_back();
			}
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


	//TreeNode *root = new TreeNode(1);
	//TreeNode *node1 = new TreeNode(2);

	//root->left = node1;

	return 0;
}