#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNodeLever
{
	TreeNode *treeNode;
	int level;
};

//�������������ʹ�ö���ʵ��
vector<vector<int>> levelOrder(TreeNode* root) 
{
	vector<vector<int>> resultV;

	if (root != NULL)
	{
		vector<int> v;

		queue<TreeNodeLever> q;
		TreeNodeLever nodeLever,lastNodeLever;
		nodeLever.treeNode = root;
		nodeLever.level = 0;

		q.push(nodeLever);

		//��¼��һ��TreeNodeLever��Ϣ
		lastNodeLever = nodeLever;

		while (!q.empty())
		{
			nodeLever = q.front();
			q.pop();

			if (lastNodeLever.level < nodeLever.level)//�µ�һ��
			{
				resultV.push_back(v);//����һ��ѹ��vector��
				v.clear();//���֮ǰ��vector,��ʵ���ǻ��˸��µ�vector
			}

			v.push_back(nodeLever.treeNode->val);

			//����ǰ�ڵ�����������ڵ���������
			TreeNode *tn = nodeLever.treeNode;

			if (tn->left != NULL)
			{
				TreeNodeLever newNodeLever;
				newNodeLever.treeNode = tn->left;
				newNodeLever.level = nodeLever.level + 1;
				
				q.push(newNodeLever);
			}

			if (tn->right != NULL)
			{
				TreeNodeLever newNodeLever;
				newNodeLever.treeNode = tn->right;
				newNodeLever.level = nodeLever.level + 1;

				q.push(newNodeLever);
			}

			//������һ��nodeLever
			lastNodeLever = nodeLever;
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
	v = levelOrder(node4);

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
			cout << v[i][j] << " ";

		cout << endl;
	}


	return 0;
}
