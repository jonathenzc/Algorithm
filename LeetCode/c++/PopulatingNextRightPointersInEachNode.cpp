#include <iostream>
#include <queue>

using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root) 
{
	if (root != NULL)
	{
		queue<TreeLinkNode*> q;
		q.push(root);

		int leafCnt = 1; //第i行第2^(i-1)个节点的next指向空
		int i = 0;
		while (!q.empty())
		{
			TreeLinkNode *temp = q.front();
			q.pop();

			if (temp != NULL)
			{
				i++;
				if (i == leafCnt)
				{
					temp->next = NULL;
					leafCnt = leafCnt * 2 + 1;
				}
				else
				{
					temp->next = q.front();
				}

				if(temp->left!=NULL)
					q.push(temp->left);

				if(temp->right!=NULL)
					q.push(temp->right);
			}
		}
	}
}

int main()
{
	TreeLinkNode *root = new TreeLinkNode(1);
	TreeLinkNode *node2 = new TreeLinkNode(2);
	TreeLinkNode *node3 = new TreeLinkNode(3);

	root->left = node2;
	root->right = node3;

	connect(root);

	cout << "Done\n";

	return 0;
}