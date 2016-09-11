#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	Solution(vector<int> nums) {
		v = nums;

		for (int i = 0; i < nums.size(); i++)
			map[nums[i]]++;
	}

	int pick(int target) {
		int size = map[target];

		vector<int> num;
		int cnt = 0;
		int num_i = 0;

		while(cnt<size && num_i<v.size())
		{
			if (v[num_i] == target) {
				num.push_back(num_i);
				cnt++;
			}

			num_i++;
		}

		return num[rand()%size];
	}
private:
	unordered_map<int, int> map;
	vector<int> v;
};

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);

	Solution s(v);

	cout << s.pick(3) << endl;

	return 0;
}