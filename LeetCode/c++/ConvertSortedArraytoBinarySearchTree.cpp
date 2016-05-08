#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* BSTHelper(vector<int>& nums,int start,int end)
{
	if (start > end)
		return NULL;

	int mid = (start+end)/2;

	TreeNode *node = new TreeNode(nums[mid]);
	node->left = BSTHelper(nums,start,mid-1);
	node->right = BSTHelper(nums,mid+1,end);

	return node;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
	int vSize = nums.size()-1;

	TreeNode *node = BSTHelper(nums,0,vSize);

	return node;
}

int main()
{
	vector<int> nums;

	for (int i = 0; i < 10; i++)
		nums.push_back(i);

	TreeNode *node = sortedArrayToBST(nums);

	cout << "Finished";

	return 0;
}
