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
	vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>> ret;
		if (root == NULL) {
			return ret;
		}

		queue<pair<Node*, int>> nodeLevelQ;
		nodeLevelQ.push(pair<Node*, int>(root, 0));

		int curLevel = 0;
		vector<int> traverseV;
		ret.push_back(traverseV);

		while (!nodeLevelQ.empty()) {
			pair<Node*, int> tmpPair = nodeLevelQ.front();
			nodeLevelQ.pop();

			if (curLevel != tmpPair.second) {
				curLevel++;
				vector<int> tmpV;
				ret.push_back(tmpV);
			}

			for (auto tmp : tmpPair.first->children) {
				nodeLevelQ.push(pair<Node*, int>(tmp, curLevel + 1));
			}
			ret[curLevel].push_back(tmpPair.first->val);
		}

		return ret;
	}
};

void printV(vector<vector<int>> v) {
	for (auto innerV : v) {
		for (int num : innerV) {
			cout << num << " ";
		}
		cout << endl;
	}
}

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
	printV(solution.levelOrder(node1));


	return 0;
}