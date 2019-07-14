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

struct MinCmp {
	bool operator () (pair<int, int> p1, pair<int, int> p2) {
		return p1.second < p2.second;
	}
};

class Solution {
public:
	//方法1：希尔排序,O(N)
	vector<int> topKFrequent1(vector<int>& nums, int k) {
		unordered_map<int, int> frequency;
		for (int num : nums) {
			frequency[num]++;
		}

		vector<vector<int>> shellSortBucket(nums.size() + 1);
		for (auto iter : frequency) {
			shellSortBucket[iter.second].push_back(iter.first);
		}

		vector<int> ret;
		int cnt = 0;
		int idx = nums.size();
		while (cnt < k) {
			if (shellSortBucket[idx].size() != 0) {
				int i = 0;
				while (i < shellSortBucket[idx].size()) {
					ret.push_back(shellSortBucket[idx][i]);
					cnt++;
					i++;
				}
			}
			idx--;
		}

		return ret;
	}

	//方法2：最小堆,O(nlogk)
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> frequency;
		for (int num : nums) {
			frequency[num]++;
		}

		//构建nums.size()-k个大小的最小堆
		vector<int> ret;
		priority_queue<pair<int, int>, vector<pair<int, int>>, MinCmp> heapV;
		for (auto iter = frequency.begin(); iter != frequency.end(); iter++) {
			heapV.push(make_pair(iter->first, iter->second));
			if (heapV.size() > frequency.size() - k) {
				ret.push_back(heapV.top().first);
				heapV.pop();
			}
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
	vector<int> nums1;
	nums1.push_back(5);
	nums1.push_back(5);
	nums1.push_back(5);
	nums1.push_back(9);
	nums1.push_back(9);
	nums1.push_back(15);

	printVector(s.topKFrequent(nums1, 2));
	printVector(s.topKFrequent(nums1, 3));

	vector<int> nums2;
	nums2.push_back(1);
	printVector(s.topKFrequent(nums2, 1));

	vector<int> nums3;
	nums3.push_back(1);
	nums3.push_back(2);
	printVector(s.topKFrequent(nums3, 2));

	return 0;
}