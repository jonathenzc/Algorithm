#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

//过不了一个case
//bool bigger(int a, int b)
//{
//	if (a == b)
//		return true;
//
//	stringstream ss;
//	ss << a;
//	string strA;
//	ss >> strA;
//
//	ss.clear();
//
//	ss << b;
//	string strB;
//	ss >> strB;
//
//	int aIndex = 0, bIndex = 0;
//	while (aIndex < strA.size() && bIndex < strB.size())
//	{
//		if (strA[aIndex] > strB[bIndex])
//			return true;
//		else if (strA[aIndex] < strB[bIndex])
//			return false;
//		else
//		{
//			aIndex++;
//			bIndex++;
//		}
//	}
//
//	if (aIndex == strA.size())
//	{
//		if (strB[bIndex] > strA[0])
//			return false;
//		else
//			return true;
//	}
//	else if (bIndex == strB.size())
//	{
//		if (strA[bIndex] > strB[0])
//			return true;
//		else
//			return false;
//	}
//}
//
//string largestNumber(vector<int>& nums) {
//
//	string s = "";
//	for (int i = 0; i < nums.size(); i++)
//	{
//		int max = 0;
//		int max_index = 0;
//		for (int j = i; j < nums.size(); j++)
//		{
//			if (bigger(nums[j], max))
//			{
//				max = nums[j];
//				max_index = j;
//			}
//		}
//
//		int tmp = nums[i];
//		nums[i] = max;
//		nums[max_index] = tmp;
//
//		stringstream ss;
//		ss << max;
//		string maxS;
//		ss >> maxS;
//		s += maxS;
//	}
//
//	//忽略0
//	if (s.size() > 1 && s[] == '0')
//		s = "0";
//
//	return s;
//}

//
string largestNumber(vector<int>& nums) {
	vector<string> v;
	for (int i = 0; i < nums.size(); i++)
	{
		stringstream ss;
		ss << nums[i];
		string tmpS;
		ss >> tmpS;

		v.push_back(tmpS);
	}

	sort(v.begin(), v.end(), [](string s1, string s2) { return s1 + s2 > s2 + s1; });

	string s = "";
	for (auto tmpS : v)
		s += tmpS;

	//忽略0
	if (s.size() > 1 && s[0] == '0')
		s = "0";

	return s;
}


int main()
{
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(30);
	nums.push_back(34);
	nums.push_back(5);
	nums.push_back(9);

	cout << largestNumber(nums)<<endl;

	vector<int> nums1;
	nums1.push_back(0);
	nums1.push_back(0);

	cout << largestNumber(nums1) << endl;

	//可以这样比较
	//string s1 = "943", s2 = "231";
	//cout << s1 + s2 << endl;
	//cout << s2 + s1 << endl;

	return 0;
}