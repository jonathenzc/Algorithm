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
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		if (nums.size() == 0) return nullptr;
		if (nums.size() == 1) return new TreeNode(nums[0]);

		return constructHelper(nums, 0, nums.size());
	}
private:
	TreeNode* constructHelper(vector<int>& nums, int start, int end) {
		if (start >= end) {
			return nullptr;
		}

		int maxVal = INT_MIN, maxIdx = -1;
		for (int i = start; i < end; i++) {
			if (maxVal < nums[i]) {
				maxVal = nums[i];
				maxIdx = i;
			}
		}

		TreeNode* root = new TreeNode(maxVal);
		root->left = constructHelper(nums, start, maxIdx);
		root->right = constructHelper(nums, maxIdx + 1, end);

		return root;
	}
};

void testPrint(TreeNode* treeNode) {
	queue<pair<TreeNode*, int>> treeQ;
	treeQ.push(pair<TreeNode*, int>(treeNode, 1));
	int curLv = 1;

	while (!treeQ.empty()) {
		pair<TreeNode*, int>tmpPair = treeQ.front();
		treeQ.pop();

		if (curLv != tmpPair.second) {
			curLv = tmpPair.second;
			cout << endl;
		}

		cout << tmpPair.first->val << " ";
		if (tmpPair.first->left != NULL) {
			treeQ.push(pair<TreeNode*, int>(tmpPair.first->left, tmpPair.second + 1));
		}
		if (tmpPair.first->right != NULL) {
			treeQ.push(pair<TreeNode*, int>(tmpPair.first->right, tmpPair.second + 1));
		}
	}
}

void testCase1() {
	vector<int> num;
	num.push_back(3);
	num.push_back(2);
	num.push_back(1);
	num.push_back(6);
	num.push_back(0);
	num.push_back(5);

	Solution s;
	testPrint(s.constructMaximumBinaryTree(num));
	cout << endl;
}

void testCase2() {
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	num.push_back(4);
	num.push_back(5);
	num.push_back(6);
	num.push_back(7);
	num.push_back(8);

	Solution s;
	testPrint(s.constructMaximumBinaryTree(num));
	cout << endl;
}

void testCase3() {
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	num.push_back(4);

	Solution s;
	testPrint(s.constructMaximumBinaryTree(num));
	cout << endl;
}

int main(void)
{
	testCase1();
	cout << endl;
	testCase2();
	cout << endl;
	testCase3();
	cout << endl;

	return 0;
}
