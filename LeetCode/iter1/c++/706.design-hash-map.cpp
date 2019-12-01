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
const int NOT_FOUND = -1;

class MyHashMap {
public:
	/** Initialize your data structure here. */
	MyHashMap() {
		arr = new int[SIZE];
		for (int i = 0; i < SIZE; i++) {
			arr[i] = NOT_FOUND;
		}
	}

	/** value will always be non-negative. */
	void put(int key, int value) {
		arr[key] = value;
	}

	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	int get(int key) {
		return arr[key];
	}

	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	void remove(int key) {
		arr[key] = NOT_FOUND;
	}
private:
	int* arr;
};

int main()
{
	MyHashMap myHashMap;

	myHashMap.put(1, 1);
	myHashMap.put(2, 2);
	cout << myHashMap.get(1) << endl;            // returns 1
	cout << myHashMap.get(3) << endl;            // returns -1 (not found)
	myHashMap.put(2, 1);          // update the existing value
	cout << myHashMap.get(2) << endl;            // returns 1 
	myHashMap.remove(2);          // remove the mapping for 2
	cout << myHashMap.get(2) << endl;            // returns -1 (not found) 

	return 0;
}