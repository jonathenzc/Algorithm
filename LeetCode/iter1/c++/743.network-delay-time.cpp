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
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		vector<int> dist(N + 1, INT_MAX);
		dist[K] = 0;
		for (int i = 0; i < N; i++) {
			for (vector<int> edge : times) {
				int s = edge[0], t = edge[1], cost = edge[2];
				if (dist[s] != INT_MAX && dist[t] > dist[s] + cost) {
					dist[t] = dist[s] + cost;
				}
			}
		}

		int maxVal = INT_MIN;
		for (int i = 1; i <= N; i++) {
			if (dist[i] > maxVal) {
				maxVal = dist[i];
			}
		}

		return maxVal == INT_MAX ? -1 : maxVal;
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
	vector<int>v1;
	v1.push_back(2);
	v1.push_back(1);
	v1.push_back(1);

	vector<int>v2;
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(1);

	vector<int>v3;
	v3.push_back(3);
	v3.push_back(4);
	v3.push_back(1);

	vector<vector<int>> v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	Solution s;
	cout << s.networkDelayTime(v, 4, 2) << endl;
}

int main(void)
{
	testCase1();
	cout << endl;

	return 0;
}
