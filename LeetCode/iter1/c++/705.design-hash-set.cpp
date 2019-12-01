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

const int SIZE = 1000000;

class MyHashSet {
public:
	/** Initialize your data structure here. */
	MyHashSet() {
		arr = new int[SIZE];
		for (int i = 0; i < SIZE; i++) {
			arr[i] = 0;
		}
	}

	void add(int key) {
		arr[key] = 1;
	}

	void remove(int key) {
		arr[key] = 0;
	}

	/** Returns true if this set contains the specified element */
	bool contains(int key) {
		return arr[key] == 1;
	}

private:
	int* arr;
};

int main()
{
	MyHashSet myHashSet;

	myHashSet.add(1);
	myHashSet.add(2);
	cout << myHashSet.contains(1) << endl;    // returns true
	cout << myHashSet.contains(3) << endl;    // returns false (not found)
	myHashSet.add(2);
	cout << myHashSet.contains(2) << endl;    // returns true
	myHashSet.remove(2);
	cout << myHashSet.contains(2) << endl;    // returns false (already removed)

	return 0;
}