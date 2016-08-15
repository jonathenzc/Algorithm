#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	Solution(vector<int> nums) {
		originV = nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return originV;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> v(originV);
		for (int i = 0; i < v.size(); i++)
		{
			int index = rand() % (v.size()-i);
			swap(v[i+index],v[i]);
		}

		return v;
	}
private:
	vector<int> originV;
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