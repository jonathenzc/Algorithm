#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <queue>
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

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL)
			return NULL;

		if (p == NULL && q == NULL)
			return root;
		else if (p == NULL && q != NULL)
			return q;
		else if (p != NULL && q == NULL)
			return p;
		else if (p->val == root->val)
			return p;
		else if (q->val == root->val)
			return q;
		else if (p->val < root->val && q->val < root->val)
			return lowestCommonAncestor(root->left,p,q);
		else if (p->val > root->val && q->val > root->val)
			return lowestCommonAncestor(root->right, p, q);
		else
			return root;
	}
};

int main()
{
	return 0;
}