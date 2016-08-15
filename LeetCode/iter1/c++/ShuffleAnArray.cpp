#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	Solution(vector<int> nums) {
		originV = nums;
		v = nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return originV;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		unordered_map<int, int> isUsed;

		for (int i = 0; i < v.size(); i++)
		{
			int index = rand() % v.size();
			while (isUsed.find(index) != isUsed.end())
				index = rand() % v.size();

			v[i] = originV[index];
			isUsed[index] = 1;
		}

		return v;
	}
private:
	vector<int> originV;
	vector<int> v;
};

int main()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);

	Solution s(v);

	vector<int> tmp = s.shuffle();
	for (auto i : tmp)
		cout << i << " ";

	cout << endl;

	vector<int> tmp1 = s.reset();
	for (auto i : tmp1)
		cout << i << " ";

	cout << endl;

	vector<int> tmp2 = s.shuffle();
	for (auto i : tmp2)
		cout << i << " ";

	return 0;
}