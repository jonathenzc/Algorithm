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
	int lengthLongestPath(string input) {
		vector<int> dirStack;
		string tmpPathStr = "";
		int ret = 0;
		int curLen = 0;
		int preIdx = 0;
		input += "\n";
		while (preIdx < input.length()) {
			//截取\n之间的子串
			int curIdx = input.find("\n", preIdx);
			tmpPathStr = input.substr(preIdx, curIdx - preIdx);
			preIdx = curIdx + 1;

			//获取当前路径层级，并回溯
			int level = tmpPathStr.find_last_of("\t");
			level = level == string::npos ? 0 : level + 1;
			while (dirStack.size() > level) {
				curLen -= dirStack.back();
				dirStack.pop_back();
			}

			// eg:/file.txt
			int pathLen = tmpPathStr.size() - level + 1;
			curLen += pathLen;
			dirStack.push_back(pathLen);

			if (tmpPathStr.find(".") != string::npos) {
				ret = max(curLen - 1, ret); //去除开头的/
			}
		}

		return ret;
	}
};

int main()
{
	Solution solution;
	cout << solution.lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext") << endl;
	cout << solution.lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext") << endl;

	return 0;
}