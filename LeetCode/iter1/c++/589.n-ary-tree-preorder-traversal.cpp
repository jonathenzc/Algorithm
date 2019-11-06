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

class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:
	//iterative
	vector<int> preorder(Node* root) {
		vector<int> ret;

		vector<Node*> nodeV;
		nodeV.push_back(root);

		while (!nodeV.empty()) {
			Node* node = nodeV.back();
			nodeV.pop_back();

			if (node != NULL) {
				ret.push_back(node->val);
				for (int i = node->children.size() - 1; i >= 0; i--) {
					nodeV.push_back(node->children[i]);
				}
			}
		}

		return ret;
	}

	//recursion
	//vector<int> preorder(Node* root) {
	//	vector<int> ret;
	//	if (root == NULL) {
	//		return ret;
	//	}

	//	ret.push_back(root->val);
	//	for (auto childNode : root->children) {
	//		vector<int> childPreOrder = preorder(childNode);
	//		for (int tmpVal : childPreOrder) {
	//			ret.push_back(tmpVal);
	//		}
	//	}

	//	return ret;
	//}
};

int main()
{
	vector<Node*> v5;
	Node *node5 = new Node(5, v5);

	vector<Node*> v6;
	Node *node6 = new Node(6, v6);

	vector<Node*> v3;
	v3.push_back(node5);
	v3.push_back(node6);
	Node *node3 = new Node(3, v3);

	vector<Node*> v2;
	Node *node2 = new Node(2, v2);

	vector<Node*> v4;
	Node *node4 = new Node(4, v4);

	vector<Node*> v1;
	v1.push_back(node3);
	v1.push_back(node2);
	v1.push_back(node4);
	Node *node1 = new Node(1, v1);

	Solution solution;
	vector<int> ret = solution.preorder(node1);
	for (int num : ret) {
		cout << num << " ";
	}

	return 0;
}