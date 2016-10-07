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
	int rob(TreeNode* root) {
		vector<int> v = helper(root); //大小为2，v[0]表示抢该点的最优值，v[1]表示不抢该点的最优值

		return max(v[0],v[1]);
	}


private:
	vector<int> helper(TreeNode *root)
	{
		if (root == NULL)
			return vector<int>(2,0);

		auto left = helper(root->left);
		auto right = helper(root->right);

		vector<int> ret;

		ret.push_back(root->val+left[1]+right[1]); //抢该点
		ret.push_back(max(left[0],left[1])+max(right[0],right[1])); //不抢该点

		return ret;
	}
};

int main(void)
{
	//TreeNode *root = new TreeNode(10);
	//TreeNode *node1 = new TreeNode(5);
	//TreeNode *node2 = new TreeNode(15);
	//TreeNode *node3 = new TreeNode(6);
	//TreeNode *node4 = new TreeNode(20);

	//root->left = node1;
	//root->right = node2;

	//node2->left = node3;
	//node2->right = node4;

	TreeNode *root = new TreeNode(3);
	TreeNode *node1 = new TreeNode(1);
	TreeNode *node2 = new TreeNode(5);
	TreeNode *node3 = new TreeNode(0);
	TreeNode *node4 = new TreeNode(2);
	TreeNode *node5 = new TreeNode(4);
	TreeNode *node6 = new TreeNode(6);

	root->left = node1;
	root->right = node2;

	node1->left = node3;
	node1->right = node4;

	node2->left = node5;
	node2->right = node6;

	Solution s;

	cout<<s.rob(root);

	return 0;
}