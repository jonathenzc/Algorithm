#include <iostream>
#include <vector>
#include <unordered_map>
#include <time.h>

using namespace std;

class RandomizedSet {
public:
	/** Initialize your data structure here. */
	RandomizedSet() {
		srand((int)time(0));
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		bool insertRet = false;

		if (num_map.find(val) == num_map.end()) //未找到
		{
			v.push_back(val);
			num_map[val] = v.size()-1;

			insertRet = true;
		}

		return insertRet;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		bool removeRet = false;

		if (num_map.find(val) != num_map.end()) //找到
		{
			//将容器顶部元素的下标调整成要删除的元素的下标
			int numIndex = num_map[val];
			num_map[v.back()] = numIndex;

			//从map中删除该元素
			num_map.erase(val);

			//从容器中删除该元素
			v[numIndex] = v.back();
			v.pop_back();

			removeRet = true;
		}

		return removeRet;
	}

	/** Get a random element from the set. */
	int getRandom() {
		return v[rand() % v.size()];
	}
private:
	unordered_map<int, int> num_map;
	vector<int> v;
};

int main()
{
	// Init an empty set.
	RandomizedSet randomSet;

	// Inserts 1 to the set. Returns true as 1 was inserted successfully.
	if (randomSet.insert(1))
		cout << "insert 1 Yes\n";
	else
		cout << "insert 1 No\n";

	// Returns false as 2 does not exist in the set.
	if (randomSet.remove(2))
		cout << "remove 2 Yes\n";
	else
		cout << "remove 2 No\n";

	// Inserts 2 to the set, returns true. Set now contains [1,2].
	if (randomSet.insert(2))
		cout << "insert 2 Yes\n";
	else
		cout << "insert 2 No\n";

	// getRandom should return either 1 or 2 randomly.
	cout << "Random " << randomSet.getRandom() << endl;

	// Removes 1 from the set, returns true. Set now contains [2].
	if (randomSet.remove(1))
		cout << "remove 1 Yes\n";
	else
		cout << "remove 1 No\n";

	// 2 was already in the set, so return false.
	if (randomSet.insert(2))
		cout << "insert 2 Yes\n";
	else
		cout << "insert 2 No\n";

	// Since 2 is the only number in the set, getRandom always return 2.
	cout << "Random "<<randomSet.getRandom() << endl;

	return 0;
}