#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>
#include <stack>

using namespace std;


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	TreeNode* trimBST(TreeNode* root, int L, int R) {
		if (root == NULL) {
			return NULL;
		}

		if (root->val < L) { 
			return trimBST(root->right, L, R);
		}

		if (root->val > R) {
			return trimBST(root->left, L, R);
		}

		root->left = trimBST(root->left, L, R);
		root->right = trimBST(root->right, L, R);

		return root;
	}	
};

void testPrint(TreeNode* tree) {
	if (tree != NULL) {
		testPrint(tree->left);
		cout << tree->val << endl;
		testPrint(tree->right);
	}
}

void testCase1() {
	TreeNode* t0 = new TreeNode(0);
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);

	t1->left = t0;
	t1->right = t2;

	Solution s;
	testPrint(s.trimBST(t1, 1, 2));
}

void testCase2() {
	TreeNode* t0 = new TreeNode(0);
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);

	t2->left = t1;
	t0->right = t2;

	t3->left = t0;
	t3->right = t4;

	Solution s;
	testPrint(s.trimBST(t3, 1, 3));
}

int main(void)
{
	testCase1();
	cout << endl;
	testCase2();

	return 0;
}