#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNodeLevel
{
	TreeNode *treeNode;
	int level;
};

//广度优先搜索，使用队列实现
vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
	vector<vector<int>> resultV;

	if (root != NULL)
	{
		vector<int> v;

		queue<TreeNodeLevel> q;
		TreeNodeLevel nodeLevel, lastNodeLevel;
		nodeLevel.treeNode = root;
		nodeLevel.level = 0;

		q.push(nodeLevel);

		//记录上一个TreeNodeLevel信息
		lastNodeLevel = nodeLevel;

		while (!q.empty())
		{
			nodeLevel = q.front();
			q.pop();

			if (lastNodeLevel.level < nodeLevel.level)//新的一层
			{
				if (nodeLevel.level % 2 == 0)//前一层
				{
					vector<int> reversedV = v;
					v.clear();

					for (int i = reversedV.size() - 1; i >= 0; i--)
						v.push_back(reversedV[i]);
				}

				resultV.push_back(v);//将上一层压入vector中
				v.clear();//清空之前的vector,其实就是换了个新的vector
			}

			v.push_back(nodeLevel.treeNode->val);

			//将当前节点的左右子树节点放入队列中
			TreeNode *tn = nodeLevel.treeNode;

			if (tn->left != NULL)
			{
				TreeNodeLevel newNodeLevel;
				newNodeLevel.treeNode = tn->left;
				newNodeLevel.level = nodeLevel.level + 1;

				q.push(newNodeLevel);
			}

			if (tn->right != NULL)
			{
				TreeNodeLevel newNodeLevel;
				newNodeLevel.treeNode = tn->right;
				newNodeLevel.level = nodeLevel.level + 1;

				q.push(newNodeLevel);
			}

			//保留上一个nodeLevel
			lastNodeLevel = nodeLevel;
		}

		if (nodeLevel.level % 2 == 1)//最后一层是奇数的话就将vector反一下
		{
			vector<int> reversedV = v;
			v.clear();

			for (int i = reversedV.size() - 1; i >= 0; i--)
				v.push_back(reversedV[i]);
		}

		//将最后一层的vector压入
		resultV.push_back(v);
	}

	return resultV;
}

int main()
{
	//构建这样的树
	//        5
	//	     / \
	//	    4   8
	//	   /   / \
	//	  11  13  4
	//	 /  \      \
	//	7    2      1

	TreeNode *node7 = new TreeNode(7);
	TreeNode *node2 = new TreeNode(2);
	TreeNode *node11 = new TreeNode(11);
	node11->left = node7;
	node11->right = node2;

	TreeNode *node4 = new TreeNode(4);
	node4->left = node11;

	TreeNode *node1 = new TreeNode(1);
	TreeNode *nodeAnother4 = new TreeNode(4);
	nodeAnother4->right = node1;

	TreeNode *node13 = new TreeNode(13);
	TreeNode *node8 = new TreeNode(8);
	node8->left = node13;
	node8->right = nodeAnother4;

	TreeNode *root = new TreeNode(5);
	root->left = node4;
	root->right = node8;

	vector<vector<int>> v;
	v = zigzagLevelOrder(root);

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
			cout << v[i][j] << " ";

		cout << endl;
	}


	return 0;
}
