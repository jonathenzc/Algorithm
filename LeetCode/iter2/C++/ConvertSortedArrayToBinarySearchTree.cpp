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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0)
			return NULL;

		return helper(nums, 0, nums.size());
	}
private:
	vector<int> v;

	TreeNode *helper(vector<int> &nums, int start, int size)
	{
		if (size <= 0)
			return NULL;

		int mid = size / 2;
		TreeNode *root = new TreeNode(nums[start + mid]);
		root->left = helper(nums, start, mid);
		root->right = helper(nums, start + mid + 1, size - 1 - mid);

		return root;
	}
};
