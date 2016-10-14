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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (p == NULL)
			return q;

		if (q == NULL)
			return p;

		vector<TreeNode*> pV = FindNodePath(root, p);
		vector<TreeNode*> qV = FindNodePath(root, q);

		TreeNode *ret = NULL;
		int pIndex = 0, qIndex = 0;

		while (pIndex < pV.size() && qIndex < qV.size())
		{
			if (pV[pIndex] == qV[qIndex])
				ret = pV[pIndex];
			else
				break;

			pIndex++;
			qIndex++;
		}

		return ret;
	}
private:
	vector<TreeNode*> FindNodePath(TreeNode *root, TreeNode *target)
	{
		vector<TreeNode*> ret;

		if (root == target)
			ret.push_back(target);
		else
		{
			bool isFound = false;
			ret.push_back(root);
			if (root->left != NULL)
			{
				helper(ret, root->left, target, isFound);

				if (!isFound && root->right != NULL)
				{
					ret.pop_back();
					helper(ret, root->right, target, isFound);
				}
			}
			else
				helper(ret, root->right, target, isFound);
		}

		return ret;
	}

	void helper(vector<TreeNode*> &ret, TreeNode *root, TreeNode *target, bool &isFound)
	{
		if (root == target)
		{
			ret.push_back(target);
			isFound = true;
		}
		else
		{
			if (!isFound)
			{
				ret.push_back(root);
				if (root->left != NULL)
				{
					helper(ret, root->left, target, isFound);
					if (!isFound)
					{
						ret.pop_back();
						if (root->right != NULL)
						{
							helper(ret, root->right, target, isFound);
							if (!isFound)
								ret.pop_back();
						}
					}
				}
				else {
					if (root->right != NULL)
					{
						helper(ret, root->right, target, isFound);
						if (!isFound)
							ret.pop_back();
					}
				}
			}
		}
	}
};

int main(void)
{
	TreeNode *root = new TreeNode(1);
	TreeNode *node1 = new TreeNode(2);
	TreeNode *node2 = new TreeNode(3);
	TreeNode *node3 = new TreeNode(4);
	TreeNode *node4 = new TreeNode(3);
	TreeNode *node5 = new TreeNode(5);
	TreeNode *node6 = new TreeNode(7);

	root->left = node1;
	root->right = node2;

	//node1->left = node3;
	node1->right = node3;

	//node2->left = node5;
	//node2->right = node6;

	Solution s;

	TreeNode * retNode = s.lowestCommonAncestor(root, node2, node3);
	cout << retNode->val;

	return 0;
}