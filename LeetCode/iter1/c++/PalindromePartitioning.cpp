#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(string s, int start, int end)
{
	bool retResult = true;

	while (start < end)
	{
		if (s[start] != s[end])
		{
			retResult = false;
			break;
		}

		start++;
		end--;
	}

	return retResult;
}

void helper(int i, string s, vector<string> &subV, vector<vector<string>> &v) //subV加引用会大大提高时间
{
	if (i == s.size())
	{
		v.push_back(subV);
		return;
	}
	else
	{
		for (int index = i; index < s.size(); index++)
		{
			if (isPalindrome(s, i, index))
			{
				subV.push_back(s.substr(i, index - i + 1));
				helper(index + 1, s, subV, v);
				subV.pop_back();
			}
		}
	}
}

vector<vector<string>> partition(string s) {
	vector<vector<string>> v;
	if (s.empty()) return v;
	vector<string> subV;

	helper(0, s, subV, v);

	return v;
}

vector<vector<string>> partition(string s) {
	vector<vector<string>> v;

	if (s.empty()) return v;

	vector<string> subV;

	helper(0, s, subV, v);

	return v;
}

void testPrint(string s)
{
	cout << "test " << s << endl;

	vector<vector<string>> v = partition(s);
	for (int i = 0; i < v.size(); i++)
	{
		vector<string> tmpV = v[i];
		for (int j = 0; j < tmpV.size(); j++)
			cout << tmpV[j] << " ";

		cout << endl;
	}

	cout << endl;

}


int main()
{
	testPrint("aab");
	testPrint("cdd");
	testPrint("efe");
	testPrint("xyxx");

	return 0;
}