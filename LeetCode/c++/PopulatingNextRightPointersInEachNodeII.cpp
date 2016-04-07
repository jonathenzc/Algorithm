#include <iostream>
#include <queue>

using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

struct TreeNodeLevel {
	TreeLinkNode *node;
	int level;
};

void connect(TreeLinkNode *root) {
	if (root != NULL)
	{
		queue<TreeNodeLevel> q;
		TreeNodeLevel rootLevel;
		rootLevel.level = 1;
		rootLevel.node = root;

		q.push(rootLevel);

		int crtLevel = 1;
		TreeLinkNode *lastNode = NULL;

		while (!q.empty())
		{
			TreeNodeLevel topLevel = q.front();
			q.pop();

			TreeLinkNode *topNode = topLevel.node;
			if (crtLevel != topLevel.level)
			{
				crtLevel = topLevel.level;
				lastNode->next = NULL;
			}
			else
			{
				if (lastNode != NULL)
				{
					lastNode->next = topNode;
				}
				else
					topNode->next = NULL;
			}

			lastNode = topNode;

			if (topNode->left != NULL)
			{
				TreeNodeLevel leftLevel;
				leftLevel.level = topLevel.level+1;
				leftLevel.node = topNode->left;
				q.push(leftLevel);
			}

			if (topNode->right != NULL)
			{
				TreeNodeLevel rightLevel;
				rightLevel.level = topLevel.level + 1;
				rightLevel.node = topNode->right;
				q.push(rightLevel);
			}
		}
	}
}

int main()
{
	TreeLinkNode *root = new TreeLinkNode(1);
	TreeLinkNode *node1 = new TreeLinkNode(2);
	TreeLinkNode *node2 = new TreeLinkNode(3);

	TreeLinkNode *node3 = new TreeLinkNode(4);
	TreeLinkNode *node4 = new TreeLinkNode(5);
	TreeLinkNode *node6 = new TreeLinkNode(6);

	root->left = node1;
	root->right = node2;

	//node1->left = node3;
	//node1->right = node4;

	//node2->right = node6;

	connect(root);

	return 0;
}
