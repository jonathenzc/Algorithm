#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>
#include <stack>

using namespace std;


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		stack<TreeNode*> treeNodeSt;
		treeNodeSt.push(root);
		string ret = "";
		while (!treeNodeSt.empty()) {
			TreeNode* treeNode = treeNodeSt.top();
			treeNodeSt.pop();

			if (treeNode == nullptr) {
				ret += "# ";
			}
			else {
				ret += to_string(treeNode->val) + " ";
				treeNodeSt.push(treeNode->right);
				treeNodeSt.push(treeNode->left);
			}
		}

		return ret;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		queue<string> splittedQ;
		int i = -1, preI = 0;
		while (i < (signed)data.size()) {
			preI = i + 1;
			i = data.find(" ", preI);
			if (i == -1) {
				break;
			}
			splittedQ.push(data.substr(preI, i - preI));
		}

		return deserializeHelper(splittedQ);
	}
private:
	TreeNode* deserializeHelper(queue<string>& q) {
		if (q.empty()) {
			return nullptr;
		}

		string qtop = q.front();
		q.pop();
		if (qtop == "#") {
			return nullptr;
		}

		TreeNode* root = new TreeNode(atoi(qtop.c_str()));
		root->left = deserializeHelper(q);
		root->right = deserializeHelper(q);

		return root;
	}
};

void testPrint(TreeNode* treeNode) {
	queue<pair<TreeNode*, int>> treeQ;
	treeQ.push(pair<TreeNode*, int>(treeNode, 1));
	int curLv = 1;

	while (!treeQ.empty()) {
		pair<TreeNode*, int>tmpPair = treeQ.front();
		treeQ.pop();

		if (curLv != tmpPair.second) {
			curLv = tmpPair.second;
			cout << endl;
		}

		cout << tmpPair.first->val << " ";
		if (tmpPair.first->left != NULL) {
			treeQ.push(pair<TreeNode*, int>(tmpPair.first->left, tmpPair.second + 1));
		}
		if (tmpPair.first->right != NULL) {
			treeQ.push(pair<TreeNode*, int>(tmpPair.first->right, tmpPair.second + 1));
		}
	}
}

void testCase1() {
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	t1->left = t2;

	testPrint(t1);
	cout << endl;

	Solution s;
	string str = s.serialize(t1);
	cout << str << endl;
	testPrint(s.deserialize(str));
	cout << endl;
}

void testCase2() {
	TreeNode* t1 = new TreeNode(11);
	TreeNode* t2 = new TreeNode(21);
	TreeNode* t3 = new TreeNode(31);
	TreeNode* t4 = new TreeNode(41);
	TreeNode* t5 = new TreeNode(51);
	TreeNode* t6 = new TreeNode(61);

	t2->left = t3;
	t2->right = t1;

	t6->left = t5;

	t4->left = t2;
	t4->right = t6;

	testPrint(t4);
	cout << endl;

	Solution s;
	string str = s.serialize(t4);
	cout << str << endl;
	testPrint(s.deserialize(str));
	cout << endl;
}

void testCase3() {
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);

	t2->left = t3;
	t2->right = t1;
	t2->left = t3;

	t4->left = t2;

	testPrint(t4);
	cout << endl;

	Solution s;
	string str = s.serialize(t4);
	cout << str << endl;
	testPrint(s.deserialize(str));
	cout << endl;
}

int main(void)
{
	testCase1();
	cout << endl;
	testCase2();
	cout << endl;
	testCase3();

	return 0;
}