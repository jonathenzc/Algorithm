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
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (s == NULL && t == NULL) {
			return true;
		}

		if ((s == NULL && t != NULL) ||
			(s != NULL && t == NULL)) {
			return false;
		}

		return matchHelper(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
	}
private:
	bool matchHelper(TreeNode* s, TreeNode* t) {
		if (s == NULL && t == NULL) {
			return true;
		}

		if ((s == NULL && t != NULL) ||
			(s != NULL && t == NULL)) {
			return false;
		}

		if (s->val == t->val) {
			return matchHelper(s->left, t->left) && matchHelper(s->right, t->right);
		}
		return false;
	}
};

void testPrint(vector<int> v) {
	for (int num : v) {
		cout << num << " ";
	}
	cout << endl;
}

void testCase1() {
	TreeNode* s1 = new TreeNode(1);
	TreeNode* s2 = new TreeNode(2);
	TreeNode* s3 = new TreeNode(3);
	TreeNode* s4 = new TreeNode(4);
	TreeNode* s5 = new TreeNode(5);

	s4->left = s1;
	s4->right = s2;
	s3->left = s4;
	s3->right = s5;

	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t4 = new TreeNode(4);
	t4->left = t1;
	t4->right = t2;

	Solution s;
	cout << (s.isSubtree(s3, t4) ? "true" : "false") << endl;
}

void testCase2() {
	TreeNode* s0 = new TreeNode(0);
	TreeNode* s1 = new TreeNode(1);
	TreeNode* s2 = new TreeNode(2);
	TreeNode* s3 = new TreeNode(3);
	TreeNode* s4 = new TreeNode(4);
	TreeNode* s5 = new TreeNode(5);

	s2->left = s0;
	s4->left = s1;
	s4->right = s2;
	s3->left = s4;
	s3->right = s5;

	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t4 = new TreeNode(4);
	t4->left = t1;
	t4->right = t2;

	Solution s;
	cout << (s.isSubtree(s4, t4) ? "true" : "false") << endl;
}

int main(void)
{
	testCase1();
	testCase2();

	return 0;
}