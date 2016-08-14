#include <iostream>
#include <vector>
#include <unordered_map>
#include <time.h>

using namespace std;

class RandomizedCollection {
public:
	/** Initialize your data structure here. */
	RandomizedCollection() {
		srand((int)time(0));
	}

	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		bool result = false;

		if (num_map.find(val) == num_map.end())
			result = true;

		num_map[val].push_back(v.size());
		v.push_back(val);

		return result;
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		bool result = false;

		if (num_map.find(val) != num_map.end())
		{
			//获取下标所在的位置
			int num_index = num_map[val].back();

			if (num_map[val].size() > 1)
			{
				num_map[val].pop_back();
				num_map[v.back()].pop_back();
				num_map[v.back()].push_back(num_index);

				//num_map[v.back()].back() = num_index;
			}
			else
			{
				num_map[v.back()].pop_back();
				num_map[v.back()].push_back(num_index);

				//num_map[v.back()].back() = num_index;
				num_map.erase(val);
			}

			v[num_index] = v.back();
			v.pop_back();

			result = true;
		}

		return result;
	}

	/** Get a random element from the collection. */
	int getRandom() {
		return v[rand()%v.size()];
	}
private:
	unordered_map<int, vector<int>> num_map;
	vector<int> v;
};

int main()
{
	// Init an empty set.
	RandomizedCollection collection;

	//// Inserts 1 to the collection. Returns true as the collection did not contain 1.
	//if (collection.insert(1))
	//	cout << "insert 1 Yes\n";
	//else
	//	cout << "insert 1 No\n";

	//// Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
	//if (collection.insert(1))
	//	cout << "insert 1 Yes\n";
	//else
	//	cout << "insert 1 No\n";

	//// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
	//if (collection.insert(2))
	//	cout << "insert 2 Yes\n";
	//else
	//	cout << "insert 2 No\n";

	//// getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
	//cout<<"Random "<<collection.getRandom()<<endl;

	//// Removes 1 from the collection, returns true. Collection now contains [1,2].
	//if (collection.remove(1))
	//	cout << "remove 1 Yes\n";
	//else
	//	cout << "remove 1 No\n";

	// getRandom should return 1 and 2 both equally likely.
	//cout<<"Random "<<collection.getRandom()<<endl;



	if (collection.insert(0))
		cout << "insert 0 Yes\n";
	else
		cout << "insert 0 No\n";

	if (collection.remove(0))
		cout << "remove 0 Yes\n";
	else
		cout << "remove 0 No\n";

	if (collection.insert(-1))
		cout << "insert -1 Yes\n";
	else
		cout << "insert -1 No\n";

	if (collection.remove(0))
		cout << "remove 0 Yes\n";
	else
		cout << "remove 0 No\n";

	return 0;
}