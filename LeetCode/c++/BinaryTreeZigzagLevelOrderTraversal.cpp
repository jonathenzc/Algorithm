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

//�������������ʹ�ö���ʵ��
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

		//��¼��һ��TreeNodeLevel��Ϣ
		lastNodeLevel = nodeLevel;

		while (!q.empty())
		{
			nodeLevel = q.front();
			q.pop();

			if (lastNodeLevel.level < nodeLevel.level)//�µ�һ��
			{
				if (nodeLevel.level % 2 == 0)//ǰһ��
				{
					vector<int> reversedV = v;
					v.clear();

					for (int i = reversedV.size() - 1; i >= 0; i--)
						v.push_back(reversedV[i]);
				}

				resultV.push_back(v);//����һ��ѹ��vector��
				v.clear();//���֮ǰ��vector,��ʵ���ǻ��˸��µ�vector
			}

			v.push_back(nodeLevel.treeNode->val);

			//����ǰ�ڵ�����������ڵ���������
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

			//������һ��nodeLevel
			lastNodeLevel = nodeLevel;
		}

		if (nodeLevel.level % 2 == 1)//���һ���������Ļ��ͽ�vector��һ��
		{
			vector<int> reversedV = v;
			v.clear();

			for (int i = reversedV.size() - 1; i >= 0; i--)
				v.push_back(reversedV[i]);
		}

		//�����һ���vectorѹ��
		resultV.push_back(v);
	}

	return resultV;
}

int main()
{
	//������������
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
