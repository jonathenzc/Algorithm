#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <sstream>
#include <iomanip>
#include <queue>
#include <utility>

using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root != NULL)
		{
			q.push(pair<TreeLinkNode*,int>(root,1));

			TreeLinkNode *preNode = root;
			int preLevel = 1;

			while (!q.empty())
			{
				pair<TreeLinkNode*, int> QTop = q.front();
				q.pop();

				if (QTop.second == preLevel + 1)
				{
					preNode->next = NULL;
					preLevel++;
				}
				else {
					preNode->next = QTop.first;
				}

				preNode = QTop.first;

				if(QTop.first->left != NULL)
					q.push(pair<TreeLinkNode*,int>(QTop.first->left,QTop.second+1));

				if (QTop.first->right != NULL)
					q.push(pair<TreeLinkNode*, int>(QTop.first->right, QTop.second + 1));
			}

			preNode->next = NULL;
		}
	}
private:
	queue<pair<TreeLinkNode*,int>> q;
};

int main()
{
	Solution s;


	return 0;
}