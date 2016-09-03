#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		string s = "(";
		
		helper(s,n-1,n);

		return v;
	}
private:
	vector<string> v;

	void helper(string s,int leftCnt,int rightCnt)
	{
		if (leftCnt == 0 && rightCnt == 0)
			v.push_back(s);
		else
		{
			string tmpS = s;
			if (leftCnt > 0)
			{
				tmpS += "(";
				helper(tmpS,leftCnt-1,rightCnt);
				tmpS.pop_back();
			}

			if (leftCnt < rightCnt) {
				tmpS += ")";
				helper(tmpS, leftCnt, rightCnt - 1);
			}
		}
	}
};


void testPrint(vector<string> v)
{
	cout << "v size " << v.size()<<endl;

	for (auto s : v)
		cout << s << endl;
}

int main()
{
	Solution s;

	auto v = s.generateParenthesis(3);
	testPrint(v);

	return 0;
}