#include <iostream>
#include <string>
#include <vector>

using namespace std;

string digitArray[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };

void combinationHelper(vector<string> &v, string digits,string s,int index)
{
	if (index == digits.size())
		v.push_back(s);
	else
	{
		string digitLetter = digitArray[digits[index] - '0'];

		for (int j = 0; j < digitLetter.size(); j++)
		{
			string newS = s + digitLetter[j];
			combinationHelper(v, digits, newS, index + 1);
		}
	}
}

vector<string> letterCombinations(string digits) {
	vector<string> v;

	if (digits.size() > 0)
	{
		//string digitLetter = digitArray[digits[0] - '0'];

		//for (int j = 0; j < digitLetter.size(); j++)
		//{
		//	string s = "";
		//	s += digitLetter[j];
		//	combinationHelper(v, digits, s, 1);
		//}

		string s = "";
		combinationHelper(v,digits,s,0);
	}

	return v;
}


int main()
{
	vector<string> v = letterCombinations("234");
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	return 0;
}
