/*
 * @lc app=leetcode id=532 lang=cpp
 *
 * [532] K-diff Pairs in an Array
 */

// @lc code=start
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) {
			return 0;
		}
		int pairsCnt = 0;
		unordered_map<int, unordered_set<int>> key2Used;
		for (int num : nums) {
			if (key2Used.find(num - k) == key2Used.end() &&
				key2Used.find(num + k) == key2Used.end()) {
				unordered_set<int> tmpSet;
				key2Used[num] = tmpSet;
			}
			else {
				if (key2Used.find(num - k) != key2Used.end()) {
					if (key2Used[num - k].count(num) == 0) {
						pairsCnt++;
						key2Used[num - k].insert(num);
						key2Used[num].insert(num - k);
					}
				}
				if (key2Used.find(num + k) != key2Used.end()) {
					if (key2Used[num + k].count(num) == 0) {
						pairsCnt++;
						key2Used[num + k].insert(num);
						key2Used[num].insert(num + k);
					}
				}
			}
		}

		return pairsCnt;
    }
};
// @lc code=end

