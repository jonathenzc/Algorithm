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
	int countNodes(TreeNode* root) {
		int sum = 0;
		int leftLevel = 0;
		int rightLevel = 0;
		int lastLevelCnt = 0;
	
		if (root != NULL)
		{
			TreeNode *lNode = root;
			while (lNode != NULL)
			{
				leftLevel++;
				lNode = lNode->left;
			}

			TreeNode *rNode = root;
			while (rNode != NULL)
			{
				rightLevel++;
				rNode = rNode->right;
			}

			if (leftLevel == rightLevel)
				return pow(2, rightLevel) - 1;
			else {
				return 1 + countNodes(root->left) + countNodes(root->right);
			}
		}

		return sum;
	}
};

int main()
{
	TreeNode *root = new TreeNode(1);
	TreeNode *node1 = new TreeNode(2);
	TreeNode *node2 = new TreeNode(3);

	root->left = node1;
	root->right = node2;

	Solution s;

	cout << s.countNodes(root);


	return 0;
}