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
	int maxDepth_Recursion(Node* root) {
		if (root == NULL) {
			return 0;
		}

		if (root->children.size() == 0) {
			return 1;
		}

		int depth = 0;
		for (Node* node : root->children) {
			depth = max(depth, maxDepth_Recursion(node) + 1);
		}

		return depth;
	}

	//iteration
	int maxDepth(Node* root) {
		if (root == NULL) {
			return 0;
		}

		queue<pair<Node*, int>> q;
		q.push(pair<Node*, int>(root, 1));

		int ret = 0;
		while (!q.empty()) {
			pair<Node*, int> node = q.front();
			q.pop();

			ret = max(ret, node.second);

			for (Node* childrenNode : node.first->children) {
				q.push(pair<Node*, int>(childrenNode, node.second + 1));
			}
		}

		return ret;
	}
};

void printV(vector<double> v) {
	for (double num : v) {
		cout << num << " ";
	}
}

int main()
{
	vector<Node*> v1, v2, v3, v4, v5, v6;

	Node* node1 = new Node(1, v1);
	Node* node2 = new Node(3, v2);
	Node* node3 = new Node(2, v3);
	Node* node4 = new Node(4, v4);
	Node* node5 = new Node(5, v5);
	Node* node6 = new Node(6, v6);

	node3->children.push_back(node5);
	node3->children.push_back(node6);

	node1->children.push_back(node3);
	node1->children.push_back(node2);
	node1->children.push_back(node4);


	Solution s;
	cout << s.maxDepth(node1) << endl;

	return 0;
}