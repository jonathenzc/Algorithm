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
	vector<string> subdomainVisits(vector<string>& cpdomains) {
		//构建域名与访问次数的映射
		unordered_map<string, int> domain2Cnt;
		for (string s : cpdomains) {
			int spaceIdx = s.find(' ');
			int visit = string2int(s.substr(0, spaceIdx));

			domain2Cnt[s.substr(spaceIdx + 1)] += visit;

			int dotIdx = s.find_last_of('.');
			while (dotIdx >= 0) {
				string domain = s.substr(dotIdx + 1);
				domain2Cnt[domain] += visit;
				dotIdx = s.find_last_of('.', dotIdx - 1);
			}
		}

		//拼接返回字符串
		vector<string> ret;
		for (auto iter = domain2Cnt.begin(); iter != domain2Cnt.end(); iter++) {
			ret.push_back(to_string(iter->second) + " " + iter->first);
		}


		return ret;
	}
private:
	int string2int(string s) {
		int ret;
		stringstream ss;
		ss << s;
		ss >> ret;
		return ret;
	}
};

void print(vector<string> v) {
	for (string s : v) {
		cout << s << endl;
	}
}

int main(void)
{
	Solution s;
	vector<string> v1;
	v1.push_back("9001 discuss.leetcode.com");
	print(s.subdomainVisits(v1));

	vector<string> v2;
	v2.push_back("900 google.mail.com");
	v2.push_back("50 yahoo.com");
	v2.push_back("1 intel.mail.com");
	v2.push_back("5 wiki.org");
	print(s.subdomainVisits(v2));

	return 0;
}