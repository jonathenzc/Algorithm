#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//方法1：空间复杂度是O(n)
//class BSTIterator {
//public:
//	BSTIterator(TreeNode *root) {
//		buildQueue(root);
//	}
//
//	/** @return whether we have a next smallest number */
//	bool hasNext() {
//		return !q.empty();
//	}
//
//	void buildQueue(TreeNode *root)
//	{
//		if (root != NULL)
//		{
//			buildQueue(root->left);
//			q.push(root->val);
//			buildQueue(root->right);
//		}
//	}
//
//	/** @return the next smallest number */
//	int next() {
//		int nextInt = q.front();
//		q.pop();
//		return nextInt;
//	}
//private:
//	queue<int> q;
//};


//方法2：空间复杂度是O(h)
class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		buildStack(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !st.empty();
	}

	void buildStack(TreeNode *root)
	{
		while (root != NULL)
		{
			st.push(root);
			root = root->left;
		}
	}

	/** @return the next smallest number */
	int next() {
		TreeNode *node = st.top();
		st.pop();
		buildStack(node->right);

		return node->val;
	}
private:
	stack<TreeNode*> st;
};

int main()
{
	TreeNode* one = new TreeNode(1);
	TreeNode* two = new TreeNode(2);
	TreeNode* three = new TreeNode(3);
	TreeNode* four = new TreeNode(4);
	TreeNode* five = new TreeNode(5);
	TreeNode* six = new TreeNode(6);
	TreeNode* seven = new TreeNode(7);

	one->right = two;

	three->left = one;
	three->right = four;

	five->left = three;
	
	six->right = seven;

	five->right = six;

	BSTIterator iter(five);

	while (iter.hasNext())
		cout << iter.next() << " ";

	return 0;
}