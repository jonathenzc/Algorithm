class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		//InOrderHelper(root);

		pushLeftSubTree(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !st.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode *topNode = st.back();
		st.pop_back();

		if (topNode->right != NULL)
			pushLeftSubTree(topNode->right);

		return topNode->val;
	}

	//使用队列
	/** @return whether we have a next smallest number */
	bool hasNextQueue() {
		return !q.empty();
	}

	/** @return the next smallest number */
	int nextQueue() {
		int val = q.front();
		q.pop();

		return val;
	}
private:
	queue<int> q; //时间：O(1)，空间：O(n)

	vector<TreeNode*> st; //时间：O(1),空间O(h)

	void InOrderHelper(TreeNode *root)
	{
		if (root != NULL)
		{
			InOrderHelper(root->left);
			q.push(root->val);
			InOrderHelper(root->right);
		}
	}

	void pushLeftSubTree(TreeNode *root)
	{
		while (root != NULL)
		{
			st.push_back(root);
			root = root->left;
		}
	}
};