#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildHelper(vector<int>& postorder, vector<int>& inorder, int postStart, int inStart, int size)
{
	if (size <= 0)
		return NULL;

	int postInt = postorder[postStart+size-1];

	TreeNode *node = new TreeNode(postInt);
	int nodeIndex = 0;
	for (int i = inStart; i < inStart + size; i++)
	{
		if (inorder[i] == postInt)
		{
			nodeIndex = i;
			break;
		}
	}

	int subTreeSize = nodeIndex-inStart;

	node->left = buildHelper(postorder,inorder, postStart,inStart,subTreeSize);
	node->right = buildHelper(postorder,inorder, postStart +subTreeSize,nodeIndex+1, size- subTreeSize -1);

	return node;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	TreeNode* root = buildHelper(postorder, inorder, 0, 0, postorder.size());

	return root;
}

int main()
{
	vector<int> postorder,inorder;
	//postorder.push_back(4);
	postorder.push_back(5);
	postorder.push_back(2);
	postorder.push_back(6);
	postorder.push_back(3);
	postorder.push_back(1);

	//inorder.push_back(4);
	inorder.push_back(2);
	inorder.push_back(5);
	inorder.push_back(1);
	inorder.push_back(3);
	inorder.push_back(6);

	TreeNode *root = buildTree(inorder, postorder);

	cout << "Finish";



	return 0;
}
