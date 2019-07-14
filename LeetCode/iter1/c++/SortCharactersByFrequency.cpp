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

struct MaxCmp {
	bool operator () (pair<int, int> p1, pair<int, int> p2) {
		return p1.second < p2.second;
	}
};

class Solution {
public:

	//方法1：希尔排序,O(N)
	string frequencySort(string s) {
		unordered_map<char, int> frequency;
		for (char ch : s) frequency[ch]++;

		vector<vector<char>> shellSortBucket(s.size() + 1);
		for (auto iter : frequency) {
			shellSortBucket[iter.second].push_back(iter.first);
		}

		string ret = "";
		for (int i = s.size(); i >= 0; i--) {
			for (int j = 0; j < shellSortBucket[i].size(); j++) {
				int cnt = 0;
				while (cnt++ < i) ret += shellSortBucket[i][j];
			}
		}

		return ret;
	}

	//方法2：最小堆,O(nlogk)
	string frequencySort1(string s) {
		unordered_map<char, int> frequency;
		for (char ch : s) frequency[ch]++;

		priority_queue<pair<int, int>, vector<pair<int, int>>, MaxCmp> heapV;
		for (auto iter = frequency.begin(); iter != frequency.end(); iter++) {
			heapV.push(make_pair(iter->first, iter->second));
		}

		string ret = "";
		while (!heapV.empty()) {
			for (int i = 0; i < heapV.top().second; i++) {
				ret += heapV.top().first;
			}
			heapV.pop();
		}

		return ret;
	}
};

void printVector(vector<int> v) {
	for (int num : v) {
		cout << num << " ";
	}
	cout << endl;
}

int main(void)
{
	Solution s;
	cout << s.frequencySort("tree") << endl;
	cout << s.frequencySort("cccaaa") << endl;
	cout << s.frequencySort("Aabb") << endl;

	return 0;
}