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
	int findSecondMinimumValue(TreeNode* root) {
		if (root == NULL || (root->left == NULL && root->right == NULL)) {
			return -1;
		}
		int leftMin = root->left->val, rightMin = root->right->val;
		if (root->val == root->left->val) {
			leftMin = findSecondMinimumValue(root->left);
		}
		if (root->val == root->right->val) {
			rightMin = findSecondMinimumValue(root->right);
		}

		if (leftMin != -1 && rightMin != -1) {
			return min(leftMin, rightMin);
		}
		if (rightMin != -1) {
			return rightMin;
		}
		if (leftMin != -1) {
			return leftMin;
		}

		return -1;
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
	TreeNode* t0 = new TreeNode(2);
	TreeNode* t1 = new TreeNode(2);
	TreeNode* t2 = new TreeNode(5);
	TreeNode* t3 = new TreeNode(5);
	TreeNode* t4 = new TreeNode(7);

	t2->left = t3;
	t2->right = t4;

	t0->left = t1;
	t0->right = t2;

	Solution s;
	cout << s.findSecondMinimumValue(t0) << endl;
}

void testCase2() {
	TreeNode* t0 = new TreeNode(2);
	TreeNode* t1 = new TreeNode(2);
	TreeNode* t2 = new TreeNode(2);

	t0->left = t1;
	t0->right = t2;

	Solution s;
	cout << s.findSecondMinimumValue(t0) << endl;
}

void testCase3() {
	TreeNode* t0 = new TreeNode(2);
	TreeNode* t1 = new TreeNode(2);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(5);
	TreeNode* t4 = new TreeNode(2);
	TreeNode* t5 = new TreeNode(2);
	TreeNode* t6 = new TreeNode(2);
	TreeNode* t7 = new TreeNode(2);
	TreeNode* t8 = new TreeNode(4);
	TreeNode* t9 = new TreeNode(2);
	TreeNode* t10 = new TreeNode(3);

	t5->left = t7;
	t5->right = t8;

	t6->left = t9;
	t6->right = t10;

	t1->left = t3;
	t1->right = t4;
	t2->left = t5;
	t2->right = t6;

	t0->left = t1;
	t0->right = t2;

	Solution s;
	cout << s.findSecondMinimumValue(t0)<<endl;
}

void testCase4() {
	TreeNode* t0 = new TreeNode(2);

	Solution s;
	cout << s.findSecondMinimumValue(t0) << endl;
}

void testCase5() {
	TreeNode* t0 = new TreeNode(1);
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(3);
	TreeNode* t3 = new TreeNode(1);
	TreeNode* t4 = new TreeNode(1);
	TreeNode* t5 = new TreeNode(3);
	TreeNode* t6 = new TreeNode(4);
	TreeNode* t7 = new TreeNode(3);
	TreeNode* t8 = new TreeNode(1);
	TreeNode* t9 = new TreeNode(1);
	TreeNode* t10 = new TreeNode(1);
	TreeNode* t11 = new TreeNode(3);
	TreeNode* t12 = new TreeNode(8);
	TreeNode* t13 = new TreeNode(4);
	TreeNode* t14 = new TreeNode(8);
	TreeNode* t15 = new TreeNode(3);
	TreeNode* t16 = new TreeNode(3);
	TreeNode* t17 = new TreeNode(1);
	TreeNode* t18 = new TreeNode(6);
	TreeNode* t19 = new TreeNode(2);
	TreeNode* t20 = new TreeNode(1);

	t7->left = t15;
	t7->right = t16;

	t8->left = t17;
	t8->right = t18;

	t3->left = t7;
	t3->right = t8;

	t9->left = t19;
	t9->right = t20;
	
	t4->left = t9;
	t4->right = t10;
	
	t1->left = t3;
	t1->right = t4;

	t5->left = t11;
	t5->right = t12;
	t6->left = t13;
	t6->right = t14;

	t2->left = t5;
	t2->right = t6;

	t0->left = t1;
	t0->right = t2;

	Solution s;
	cout << s.findSecondMinimumValue(t0) << endl;
}

int main(void)
{
	testCase1();
	testCase2();
	testCase3();
	testCase4();
	testCase5();

	return 0;
}