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

	bool isSameTree(TreeNode* p, TreeNode* q) {

		return helper(p,q);
	}

private:
	bool helper(TreeNode *node1, TreeNode *node2)
	{
		bool ret = false;

		if ((node1 == NULL && node2 != NULL) || (node1 != NULL && node2 == NULL))
			ret = false;
		else if (node1 == NULL && node2 == NULL)
			ret = true;
		else
		{
			if (node1->val == node2->val)
				ret = helper(node1->left, node2->left) && helper(node1->right,node2->right);
		}

		return ret;
	}
};

int main()
{

	return 0;
}