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

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0)
			return NULL;

		return helper(preorder, inorder,0,0,preorder.size());
	}

private:
	
	TreeNode *helper(vector<int>& preorder, vector<int>& inorder, int preStart, int instart,int size)
	{
		if (size == 0)
			return NULL;

		if (size == 1)
			return new TreeNode(preorder[preStart]);

		TreeNode *root = new TreeNode(preorder[preStart]);

		int inRootIndex = getRootIndex(inorder,preorder[preStart],instart,size);
		int leftSize = inRootIndex - instart;
		int rightSize = instart+size - 1 - inRootIndex;
		
		root->left = helper(preorder,inorder,preStart+1,instart, leftSize);
		root->right = helper(preorder, inorder, preStart + leftSize+1, inRootIndex+1, rightSize);

		return root;
	}

	int getRootIndex(vector<int> &inorder, int target,int start,int end)
	{
		int retIndex = -1;
		for (int i= start;i<start+end;i++)
		{
			if (inorder[i] == target)
			{
				retIndex = i;
				break;
			}
		}

		return retIndex;
	}
};

int main()
{
	vector<int> preorder;
	preorder.push_back(1);
	preorder.push_back(2);
	preorder.push_back(3);

	vector<int> inorder;
	inorder.push_back(1);
	inorder.push_back(3);
	inorder.push_back(2);

	Solution s;

	TreeNode *root = s.buildTree(preorder,inorder);


	return 0;
}