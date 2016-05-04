#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildHelper(vector<int>& preorder, vector<int>& inorder, int preStart, int inStart, int size)
{
	if (size <= 0)
		return NULL;

	int preInt = preorder[preStart];

	TreeNode *node = new TreeNode(preInt);
	int nodeIndex = 0;
	for (int i = inStart; i < inStart + size; i++)
	{
		if (inorder[i] == preInt)
		{
			nodeIndex = i;
			break;
		}
	}

	int subTreeSize = nodeIndex-inStart;

	node->left = buildHelper(preorder,inorder,preStart+1,inStart,subTreeSize);
	node->right = buildHelper(preorder,inorder,preStart+1+subTreeSize,nodeIndex+1, size- subTreeSize -1);

	return node;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
{
	TreeNode* root = buildHelper(preorder,inorder,0,0,preorder.size());

	return root;
}

int main()
{
	vector<int> preorder,inorder;
	preorder.push_back(1);
	preorder.push_back(2);
	preorder.push_back(4);
	//preorder.push_back(5);
	preorder.push_back(3);
	preorder.push_back(6);

	inorder.push_back(4);
	inorder.push_back(2);
	//inorder.push_back(5);
	inorder.push_back(1);
	inorder.push_back(6);
	inorder.push_back(3);

	TreeNode *root = buildTree(preorder,inorder);

	cout << "Finish";



	return 0;
}
