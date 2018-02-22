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
		int cntM = cntFirstGrid(mVec);
		int cntN = cntFirstGrid(nVec);

		return cntM*cntN;
	}
private:
	int cntFirstGrid(vector<int> v) {
		int cnt = 1;
		for (int i = 1; i < v.size(); i++) {
			if (v[i] == v[0]) {
				cnt++;
			}
			else {
				break;
			}
		}

		return cnt;
	}
};

int main(void)
{
	vector<vector<int>> v;
	vector<int> v0;
	v0.push_back(2);
	v0.push_back(2);

	vector<int> v1;
	v1.push_back(3);
	v1.push_back(3);

	v.push_back(v0);
	v.push_back(v1);

	Solution s;
	cout << s.maxCount(3, 3, v) << endl;

	return 0;
}