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

class KthLargest {
public:
	KthLargest(int k, vector<int>& nums) {
		kth = k;
		for (int i = 0; i < nums.size() && i<k; i++) {
			heapQ.push(nums[i]);
		}

		for (int i = k; i < nums.size(); i++) {
			if (nums[i] > heapQ.top()) {
				heapQ.pop();
				heapQ.push(nums[i]);
			}
		}
	}

	int add(int val) {
		if (heapQ.size() < kth) {
			heapQ.push(val);
		}
		else {
			if (val > heapQ.top()) {
				heapQ.pop();
				heapQ.push(val);
			}
		}

		return heapQ.top();
	}
private:
	//小顶堆
	priority_queue<int, vector<int>, greater<int>> heapQ;
	int kth;

	void printHeap() {
		priority_queue<int, vector<int>, greater<int>> tmpQ = heapQ;
		while (!tmpQ.empty()) {
			cout << tmpQ.top() << " ";
			tmpQ.pop();
		}
	}
};

int main(void)
{
	vector<int> nums;
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(8);
	nums.push_back(2);

	KthLargest kLargest(3, nums);
	cout << kLargest.add(3) << endl;
	cout << kLargest.add(5) << endl;
	cout << kLargest.add(10) << endl;
	cout << kLargest.add(9) << endl;
	cout << kLargest.add(4) << endl;

	cout << endl;
	vector<int> emptyV;
	KthLargest kLargest1(1, emptyV);
	cout << kLargest1.add(-3) << endl;
	cout << kLargest1.add(-2) << endl;
	cout << kLargest1.add(-4) << endl;
	cout << kLargest1.add(0) << endl;
	cout << kLargest1.add(4) << endl;

	return 0;
}