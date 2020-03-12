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

struct DQLinkNode {
	int key;
	int val;
	DQLinkNode* next;
	DQLinkNode* pre;
	DQLinkNode(int _key, int _val) : key(_key), val(_val) {
		next = nullptr;
		pre = nullptr;
	}
};

class LRUCache {
public:
	LRUCache(int capacity) {
		this->capacity = capacity;
		head = new DQLinkNode(0,0);
		head->pre = nullptr;
		tail = new DQLinkNode(0,0);
		tail->next = nullptr;
		
		head->next = tail;
		tail->pre = head;
	}

	int get(int key) {
		if (key2Node.count(key) == 0) {
			return -1;
		}
		
		int val = key2Node[key]->val;
		removeNode(key);
		insertNode(key, val);

		return val;
	}

	void put(int key, int value) {
		if (key2Node.count(key) == 1) {
			removeNode(key);
		}

		if (key2Node.size() == capacity) {		
			removeNode(head->next->key);
		}

		insertNode(key, value);
	}
private:
	unordered_map<int, DQLinkNode*> key2Node;
	int capacity;
	DQLinkNode* head;
	DQLinkNode* tail;

	void insertNode(int key, int value) {
		DQLinkNode* targetNode = new DQLinkNode(key, value);
		key2Node[key] = targetNode;

		tail->pre->next = targetNode;
		targetNode->pre = tail->pre;
		targetNode->next = tail;
		tail->pre = targetNode;
	}

	void removeNode(int key) {
		DQLinkNode* targetNode = key2Node[key];
		key2Node.erase(key);

		targetNode->pre->next = targetNode->next;
		targetNode->next->pre = targetNode->pre;

		delete targetNode;
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

void testCase1() {
	LRUCache cache(2);
	cache.put(1, 1);
	cache.put(2, 2);
	cout<<cache.get(1)<<endl;			// returns 1
	cache.put(3, 3);					// evicts key 2
	cout << cache.get(2)<<endl;			// returns -1 (not found)
	cache.put(4, 4);					// evicts key 1
	cout << cache.get(1) << endl;       // returns -1 (not found)
	cout << cache.get(3) << endl;       // returns 3
	cout << cache.get(4) << endl;       // returns 4
}

void testCase2() {
	LRUCache cache(1);
	cache.put(2, 1);
	cout << cache.get(2) << endl;		// returns 1
	cache.put(3, 2);					// evicts key 2
	cout << cache.get(2) << endl;		// returns -1 (not found)
	cout << cache.get(3) << endl;		// returns 2
}

//["LRUCache", "put", "put", "put", "put", "put", "get", "put", "get", "get", "put", "get", "put", "put", "put", "get", "put", "get", "get", "get", "get", "put", "put", "get", "get", "get", "put", "put", "get", "put", "get", "put", "get", "get", "get", "put", "put", "put", "get", "put", "get", "get", "put", "put", "get", "put", "put", "put", "put", "get", "put", "put", "get", "put", "put", "get", "put", "put", "put", "put", "put", "get", "put", "put", "get", "put", "get", "get", "get", "put", "get", "get", "put", "put", "put", "put", "get", "put", "put", "put", "put", "get", "get", "get", "put", "put", "put", "get", "put", "put", "put", "get", "put", "put", "put", "get", "get", "get", "put", "put", "put", "put", "get", "put", "put", "put", "put", "put", "put", "put"]
//[13], [7, 23], [8], [12], [3, 27], [2, 12], [5], [2, 9], [13, 4], [8, 18], [1, 7], [6], [9, 29], [8, 21], [5], [6, 30], [1, 12], [10], [4, 15], [7, 22], [11, 26], [8, 17], [9, 29], [5], [3, 4], [11, 30], [12], [4, 29], [3], [9], [6], [3, 4], [1], [10], [3, 29], [10, 28], [1, 20], [11, 13], [3], [3, 12], [3, 8], [10, 9], [3, 26], [8], [7], [5], [13, 17], [2, 27], [11, 15], [12], [9, 19], [2, 15], [3, 16], [1], [12, 17], [9, 1], [6, 19], [4], [5], [5], [8, 1], [11, 7], [5, 2], [9, 28], [1], [2, 2], [7, 4], [4, 22], [7, 24], [9, 26], [13, 28], [11, 26]]
void testCase3() {
	LRUCache cache(10);
	cache.put(10, 13);
	cache.put(3, 17);
	cache.put(6, 11);
	cache.put(10, 5);
	cache.put(9, 10);
	cout << cache.get(13) << endl;
	cache.put(2, 19);
	cout << cache.get(2) << endl;
	cout << cache.get(3) << endl;
	cache.put(5, 25);
	cout << cache.get(8) << endl;
	cache.put(9, 22);
	cache.put(5, 5);
	cache.put(1, 30);
	cout << cache.get(11) << endl;
	cache.put(9, 12);
	cout << cache.get(7) << endl;
	cout << cache.get(5) << endl;
	cout << cache.get(8) << endl;
	cout << cache.get(9) << endl;
	cache.put(4,30);
	cache.put(9, 3);
	cout << cache.get(9) << endl;
	cout << cache.get(10) << endl;
	cout << cache.get(10) << endl;
	cache.put(6, 14);
	cache.put(3, 1);
	cout << cache.get(3) << endl;
	cache.put(10, 11);
	cout << cache.get(8) << endl;
	cache.put(2, 14);
	cout << cache.get(1) << endl;
	cout << cache.get(5) << endl;
	cout << cache.get(4) << endl;
	cache.put(11, 4);
	cache.put(12, 24);
	cache.put(5, 18);
	cout << cache.get(13) << endl;
	cache.put(7, 23);
	cout << cache.get(8) << endl;
	cout << cache.get(12) << endl;
	cache.put(3, 27);
	cache.put(2, 12);
	cout << cache.get(5) << endl;
	cache.put(2, 9);
	cache.put(13, 4);
	cache.put(8, 18);
	cache.put(1, 7);
	cout << cache.get(6) << endl;
	cache.put(9, 29);
	cache.put(8, 21);
	cout << cache.get(5) << endl;
	cache.put(6, 30);
	cache.put(1, 12);
	cout << cache.get(10) << endl;
}

int main(void)
{
	testCase1();
	cout << endl;
	testCase2();
	cout << endl;
	testCase3();
	cout << endl;

	return 0;
}
