#include <iostream>
#include <string>
#include <vector>

using namespace std;

//方法1：回溯，超时
//void helper(string s1, string s2, string s3, int index1, int index2, int index3, bool &isFound)
//{
//	if (index3 == s3.size() - 1)
//	{
//		if (index1 != s1.size())
//		{
//			if (s3[index3] == s1[index1])
//				isFound = true;
//			else //index2到底
//				isFound = false;
//		}
//		else //s2没到底
//		{
//			if (s3[index3] == s2[index2])
//				isFound = true;
//			else //index1到底
//				isFound = false;
//		}
//	}
//	else
//	{
//		if (index1 != s1.size() && !isFound)
//		{
//			if (s3[index3] == s1[index1])
//				helper(s1, s2, s3, index1 + 1, index2, index3 + 1, isFound);
//		}
//
//		if (index2 != s2.size() && !isFound)
//		{
//			if (s3[index3] == s2[index2])
//				helper(s1, s2, s3, index1, index2 + 1, index3 + 1, isFound);
//		}
//	}
//}
//
//bool isInterleave(string s1, string s2, string s3) {
//	int size1 = s1.size(), size2 = s2.size(), size3 = s3.size();
//
//	if (size1 == 0 && size2 == 0 && size3 == 0)
//		return true;
//
//	if (size1 + size2 != size3)
//		return false;
//
//	if (size1 == 0 && size2 != 0) //s1为空字符串，比较s2和s3
//	{
//		for (int i = 0; i < size2; i++)
//		{
//			if (s2[i] != s3[i])
//				return false;
//		}
//
//		return true;
//	}
//
//	if (size1 != 0 && size2 == 0) //s2为空字符串，比较s1和s3
//	{
//		for (int i = 0; i < size1; i++)
//		{
//			if (s1[i] != s3[i])
//				return false;
//		}
//
//		return true;
//	}
//
//	//s1和s2都不会空字符串
//	int index1 = 0, index2 = 0, index3 = 0; //index1遍历s1，index2遍历s2,index3遍历s3
//
//	bool isFound = false;
//
//	if (s3[index3] == s1[index1])
//	{
//		helper(s1, s2, s3, index1 + 1, index2, index3 + 1, isFound);
//	}
//
//	if (s3[index3] == s2[index2] && !isFound)
//	{
//		helper(s1, s2, s3, index1, index2 + 1, index3 + 1, isFound);
//	}
//
//
//	return isFound;
//}

//方法2：动态规划
bool isInterleave(string s1, string s2, string s3) {
	int size1 = s1.size(), size2 = s2.size(), size3 = s3.size();

	if (size1 == 0 && size2 == 0 && size3 == 0) //"","",""
		return true;

	if (size1 + size2 != size3)
		return false;

	if (size1 == 0 && size2 != 0) //s1为空字符串，比较s2和s3
	{
		for (int i = 0; i < size2; i++)
		{
			if (s2[i] != s3[i])
				return false;
		}

		return true;
	}

	if (size1 != 0 && size2 == 0) //s2为空字符串，比较s1和s3
	{
		for (int i = 0; i < size1; i++)
		{
			if (s1[i] != s3[i])
				return false;
		}

		return true;
	}

	//利用动态规划比较
	bool **canBeInterLeave = new bool*[size1 +1];
	for (int i = 0; i <= size1; i++)
	{
		canBeInterLeave[i] = new bool[size2+1];
	}

	//canBeInterLeave[i][j]表示s3[0...i+j-1]能被s1[0...i-1]和s2[0...j-1]组成字符串
	//canBeInterLeave[i][j]由(canBeInterLeave[i-1][j]与s1[i-1]==s3[i+j-1])或(canBeInterLeave[i][j-1]与s2[j-1]==s3[i+j-1])决定
	canBeInterLeave[0][0] = true;

	//对第一行赋值
	for (int i = 1; i <= size2; i++)
		canBeInterLeave[0][i] = (canBeInterLeave[0][i-1] && s2[i - 1] == s3[i - 1]);

	//对第一列赋值
	for (int i = 1; i <= size1; i++)
		canBeInterLeave[i][0] = (canBeInterLeave[i-1][0] && s1[i - 1] == s3[i - 1]);

 	for (int i = 1; i <= size1; i++)
	{
		for (int j = 1; j <= size2; j++)
		{
			canBeInterLeave[i][j] = ((canBeInterLeave[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (canBeInterLeave[i][j - 1] && s2[j - 1] == s3[i + j - 1]));
		}
	}

	return canBeInterLeave[size1][size2];
}

void testPrint(string s1, string s2, string s3)
{
	if (isInterleave(s1, s2, s3))
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main()
{
	testPrint("aabcc", "dbbca", "aadbbcbcac");
	testPrint("aabcc", "dbbca", "aadbbbaccc");
	testPrint("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa",
		"babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab",
		"babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab");

	testPrint("","","");
	testPrint("db","b","cbb");


	return 0;
}