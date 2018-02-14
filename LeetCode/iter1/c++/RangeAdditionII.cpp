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

class Solution {
public:
	int maxCount(int m, int n, vector<vector<int>>& ops) {
		vector<int> mVec(m);
		vector<int> nVec(n);

		//遍历每个容器
		for (int i = 0; i < ops.size(); i++) {
			//遍历当前容器	
			for (int k = 0; k < ops[i][0]; k++) {
				mVec[k]++;
			}

			for (int k = 0; k < ops[i][1]; k++) {
				nVec[k]++;
			}
		}

		//遍历mVec和nVec统计个数
		int target;

		int cnt = 1;
		for (int i = 1; i < mVec.size(); i++) {
			if (mVec[i] == mVec[0]) {

			}
		}


		return cnt;
	}
};

void testPrint(vector<int> v) {
	Solution s;

	if (s.isOneBitCharacter(v))
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main(void)
{
	vector<int> v0;
	v0.push_back(1);
	v0.push_back(1);
	v0.push_back(0);

	testPrint(v0);

	vector<int> v1;
	v1.push_back(1);
	v1.push_back(0);

	testPrint(v1);

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(0);
	v2.push_back(0);

	testPrint(v2);

	vector<int> v3;
	v3.push_back(0);
	v3.push_back(0);
	v3.push_back(0);
	v3.push_back(0);

	testPrint(v3);

	vector<int> v4;
	v4.push_back(0);
	v4.push_back(0);
	v4.push_back(1);
	v4.push_back(0);

	testPrint(v4);

	vector<int> v5;
	v5.push_back(1);
	v5.push_back(0);
	v5.push_back(1);
	v5.push_back(0);

	testPrint(v5);

	return 0;
}