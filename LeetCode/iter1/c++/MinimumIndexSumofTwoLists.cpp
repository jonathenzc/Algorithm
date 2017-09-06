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
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		unordered_map<string, int> restaurantMap;
		for (int i = 0; i < list1.size(); i++)
			restaurantMap[list1[i]] = i + 1;

		vector<string> v;
		int minSum = INT_MAX;
		for (int i = 0; i < list2.size(); i++)
		{
			int list1_key = restaurantMap[list2[i]];
			if (list1_key != 0) {
				if (minSum > list1_key + i)
				{
					minSum = list1_key + i;
					v.clear();
					v.push_back(list2[i]);
				}
				else if (minSum == list1_key + i)
				{
					v.push_back(list2[i]);
				}
			}
		}

		return v;
	}
};

void testPrint(vector<string> l1, vector<string> l2)
{
	Solution ss;
	vector<string> v = ss.findRestaurant(l1, l2);
	for (string s : v)
		cout << s << endl;
}

int main(void)
{
	vector<string> v1;
	v1.push_back("a");
	v1.push_back("b");
	v1.push_back("c");
	v1.push_back("d");

	vector<string> v2;
	v2.push_back("d");
	v2.push_back("e");
	v2.push_back("c");
	v2.push_back("a");

	testPrint(v1, v2);

	return 0;
}