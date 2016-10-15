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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if (root != NULL)
		{
			q.push(pair<TreeNode*,int>(root,1));
			int preLevel = 1;

			vector<int> curV;

			while (!q.empty())
			{
				pair<TreeNode*, int> topNode = q.front();
				q.pop();

				if (topNode.second == preLevel + 1)
				{
					//层为偶数层则翻转
					if((preLevel & 1) == 0)
						reverseV(curV);

					v.push_back(curV);
					curV.clear();

					preLevel = topNode.second;
				}
				
				curV.push_back(topNode.first->val);

				if (topNode.first->left != NULL)
					q.push(pair<TreeNode*,int>(topNode.first->left,topNode.second+1));

				if (topNode.first->right != NULL)
					q.push(pair<TreeNode*, int>(topNode.first->right, topNode.second + 1));
			}

			if ((preLevel & 1) == 0)
				reverseV(curV);

			v.push_back(curV);
		}

		return v;
	}
private:
	queue<pair<TreeNode*,int>> q;

	vector<vector<int>> v;

	void reverseV(vector<int> &curV)
	{
		int start = 0, end = curV.size() - 1;
		while (start < end)
		{
			int tmpNum = curV[start];

			curV[start] = curV[end];
			curV[end] = tmpNum;

			start++;
			end--;
		}
	}
};

int main()
{
	TreeNode *root = new TreeNode(3);
	TreeNode *node1 = new TreeNode(9);
	TreeNode *node2 = new TreeNode(20);
	TreeNode *node3 = new TreeNode(15);
	TreeNode *node4 = new TreeNode(7);

	root->left = node1;
	root->right = node2;

	//node2->left = node3;
	//node2->right = node4;

	Solution s;
	vector<vector<int>> v = s.zigzagLevelOrder(root);

	for (auto tmpV : v)
	{
		for (auto num : tmpV)
			cout << num << " ";

		cout << endl;
	}

	return 0;
}