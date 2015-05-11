#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) 
{
	if (s.size() == 0 || s.size() == 1)
		return true;
	else
	{
		//先将原字符串的空格和其他非字母或数字字符去除，并将大写字母转化为小写字母
		string newS = "";
		for (int i = 0; i < s.size(); i++)
		{
			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
				newS += s[i];
			else if (s[i] >= 'A' && s[i] <= 'Z')
				newS += s[i]+32;
		}
		
		//在预处理后的字符串两端分别设置指针来比较是否为回文
		//cout << newS << endl;

		int head = 0,tail = newS.size()-1;
		bool result = true;

		while (head <= tail)
		{
			if (newS[head] != newS[tail])
			{
				result = false;
				break;
			}

			head++;
			tail--;
		}

		return result;
	}
}

int main()
{
	if (isPalindrome("1a2"))
		cout << "True";
	else
		cout << "False";

	return 0;
}