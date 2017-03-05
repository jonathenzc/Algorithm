#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		if (root == NULL)
			return "null";

		string s = "";

		q.push(root);

		while (!q.empty())
		{
			TreeNode *topNode = q.front();
			q.pop();

			if (topNode == NULL)
				s += "null,";
			else
			{
				s += int2Str(topNode->val) + ",";
				q.push(topNode->left);
				q.push(topNode->right);
			}
		}

		int end = s.size() - 1;
		while (s[end]<'0' || s[end]>'9')
			end--;

		s = s.substr(0, end + 1);

		return s;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data == "null")
			return NULL;

		buildNodeVec(data);

		TreeNode *root = v[0];

		root->left = helper(1, 0);

		if (v[1] == NULL)
			root->right = helper(2, 1);
		else
			root->right = helper(2, 0);

		return root;
	}
private:
	queue<TreeNode*> q;

	string int2Str(int num)
	{
		stringstream ss;
		ss << num;
		string s;
		ss >> s;

		return s;
	}

	vector<TreeNode*> v;

	int str2int(string s)
	{
		stringstream ss;
		ss << s;
		int num;
		ss >> num;

		return num;
	}

	void buildNodeVec(string data)
	{
		int startIndex = 0;

		while (startIndex < data.size())
		{
			int dotIndex = data.find(",", startIndex);
			if (dotIndex == -1)
				break;

			string numStr = data.substr(startIndex, dotIndex - startIndex);

			if (numStr == "null")
				v.push_back(NULL);
			else
			{
				int num = str2int(numStr);
				TreeNode *node = new TreeNode(num);
				v.push_back(node);
			}

			startIndex = dotIndex + 1;
		}

		string numStr = data.substr(startIndex, data.size() - startIndex);
		int num = str2int(numStr);
		TreeNode *node = new TreeNode(num);
		v.push_back(node);
	}

	TreeNode *helper(int rootIndex, int NULLCnt) //以v[rootIndex]为根节点的子树
	{
		if (rootIndex >= v.size())
			return NULL;

		TreeNode *root = v[rootIndex];
		if (root != NULL)
		{
			int leftChild = (rootIndex + 1 - NULLCnt) * 2 - 1;
			int rightChild = (rootIndex + 1 - NULLCnt) * 2;

			int curNULLCnt = getNULLCnt(rootIndex,leftChild);

			root->left = helper(leftChild,NULLCnt + curNULLCnt);
			root->right = helper(rightChild, NULLCnt + curNULLCnt);
		}

		return root;
	}

	int getNULLCnt(int rootIndex, int childIndex)
	{
		if (rootIndex >= v.size() || childIndex >= v.size())
			return 0;

		int cnt = 0;
		for (int i = rootIndex + 1; i <= childIndex; i++)
		{
			if (v[i] == NULL)
				cnt++;
		}

		return cnt;
	}
};

int main(void)
{
	//TreeNode *root = new TreeNode(1);
	//TreeNode *node1 = new TreeNode(2);
	//TreeNode *node2 = new TreeNode(3);
	//TreeNode *node3 = new TreeNode(4);
	//TreeNode *node4 = new TreeNode(5);
	//TreeNode *node5 = new TreeNode(6);
	//TreeNode *node6 = new TreeNode(7);
	//TreeNode *node7 = new TreeNode(8);

	//root->left = node1;
	//root->right = node2;

	//node2->left = node3;
	//node2->right = node4;

	//node4->left = node5;

	//node5->left = node6;
	//node5->right = node7;


	TreeNode *root = new TreeNode(2);
	TreeNode *node1 = new TreeNode(3);
	TreeNode *node2 = new TreeNode(4);
	TreeNode *node3 = new TreeNode(5);
	TreeNode *node4 = new TreeNode(6);

	root->right = node1;
	node1->right = node2;
	node2->right = node3;
	node3->right = node4;

	Codec s;
	cout << s.serialize(root) << endl;

	TreeNode *newRoot = s.deserialize(s.serialize(root));

	cout << "Finished\n";

	return 0;
}