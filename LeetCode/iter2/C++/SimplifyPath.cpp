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
	string simplifyPath(string path) {
		int i = 0;

		while (i < path.size())
		{
			//找下一个/
			int nextSlashIndex = path.find("/", i + 1);
			if (nextSlashIndex == -1)
				nextSlashIndex = path.size();

			string dirStr = path.substr(i + 1, nextSlashIndex - i - 1);
			if (dirStr.size() != 0)
			{
				if (dirStr.compare("..") == 0)
				{
					if(symbolSt.size() != 0)
						symbolSt.pop_back();
				}
				else if (dirStr.compare(".") != 0)
					symbolSt.push_back(dirStr);
			}

			i = nextSlashIndex;
		}

		//组合字符串
		string ret = "";
		for (int i = 0; i < symbolSt.size();i++)
			ret += "/"+symbolSt[i];

		if (ret.size() == 0)
			ret = "/";

		return ret;
	}
private:
	vector<string> symbolSt;
};

void testPrint(string s)
{
	Solution ss;
	cout << ss.simplifyPath(s) << endl;
}

int main(void)
{
	testPrint("/home/");
	testPrint("/a/./b/../../c/");
	testPrint("/../");
	testPrint("/home//foo/");



	return 0;
}