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
	//int rob(TreeNode* root) {

	//}
	vector<int> rightSideView(TreeNode* root) {
		if (root != NULL)
		{
			pair<TreeNode*, int> p(root,1);
			q.push(p);

			int preLevel = 1;
			auto topNode = q.back();
			auto preNode = topNode;

			while (!q.empty())
			{
				topNode = q.front();
				q.pop();

				if (topNode.second == preLevel + 1)
					v.push_back(preNode.first->val);

				preLevel = topNode.second;

				if (topNode.first->left != NULL)
				{
					pair<TreeNode*, int> leftP(topNode.first->left, topNode.second + 1);
					q.push(leftP);
				}

				if (topNode.first->right != NULL)
				{
					pair<TreeNode*, int> rightP(topNode.first->right, topNode.second + 1);
					q.push(rightP);
				}

				preNode = topNode;
			}

			v.push_back(topNode.first->val);
		}

		return v;
	}

private:
	int maxMoney;

	vector<int> v;

	queue<pair<TreeNode*,int>> q;
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

	//root->left = node1;
	//root->right = node2;

	//node1->left = node3;
	//node1->right = node4;

	//node2->left = node5;
	//node2->right = node6;

	Solution s;

	vector<int> v = s.rightSideView(root);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return 0;
}