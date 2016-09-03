#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	Solution() {
		digitPanal.push_back("");//0
		digitPanal.push_back("");//1
		digitPanal.push_back("abc");//2
		digitPanal.push_back("def");//3
		digitPanal.push_back("ghi");//4
		digitPanal.push_back("jkl");//5
		digitPanal.push_back("mno");//6
		digitPanal.push_back("pqrs");//7
		digitPanal.push_back("tuv");//8
		digitPanal.push_back("wxyz");//9
	}

	vector<string> letterCombinations(string digits) {
		if (digits.size() > 0) {

			string s = "";

			helper(s, digits, 0);
		}

		return v;
	}
private:
	vector<string> v;
	vector<string> digitPanal;

	void helper(string s,string digits,int index)
	{
		if (index == digits.size()) {
			v.push_back(s);
		}
		else
		{
			int pos = digits[index] - '0';
			for (int i = 0; i < digitPanal[pos].size(); i++)
				helper(s+digitPanal[pos][i],digits,index+1);
		}
	}
};

int main()
{
	Solution s;

	auto v = s.letterCombinations("23");
	cout << "v size " << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return 0;
}