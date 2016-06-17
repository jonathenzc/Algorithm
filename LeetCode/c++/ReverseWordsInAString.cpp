#include <iostream>
#include <string>

using namespace std;

void reverseWords(string &s) {

	//忽略开头的空格
	int s_index = 0;
	while(s_index < s.size())
	{
		if (s[s_index] != ' ')
			break;
		
		s_index++;
	}

	//开头没有空格
	if(s_index != 0)
		s = s.substr(s_index);

	//忽略结尾的空格
	s_index = s.size()-1;
	while (s_index >= 0)
	{
		if (s[s_index] != ' ')
			break;

		s_index--;
	}

	if (s_index != s.size() - 1)
		s = s.substr(0,s_index+1);

	//处理多余的空格
	int firstSpaceIndex = -1;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			if (firstSpaceIndex == -1)
				firstSpaceIndex = i;
		}
		else
		{
			if (firstSpaceIndex != -1 && i - firstSpaceIndex != 1)
			{
				s = s.substr(0, firstSpaceIndex + 1) + s.substr(i);
				i = firstSpaceIndex;
			}

			firstSpaceIndex = -1;
		}
	}

	//反转字符串
	int lastStart = -1, lastEnd = s.size(), start = 0, end = s.size()-1;
	string head = "", tail = "";

	while (start < end)
	{
		if (s[start] != ' ')
		{
			head += s[start];
			start++;
		}

		if (s[end] != ' ')
		{
			tail = s[end]+tail;
			end--;
		}

		if (s[start] == ' ' && s[end] == ' ')
		{
			if (lastStart == -1)
				s = tail + s.substr(start,end-start+1) + head;
			else
				s = s.substr(0, lastStart+1)+tail + s.substr(start, end - start + 1) + head+s.substr(lastEnd);

			start = lastStart + tail.size() + 2;
			end = lastEnd - head.size() - 2;

			lastStart = start-1;
			lastEnd = end+1;
			head = "";
			tail = "";
		}
	}

}

void printTest(string s)
{
	reverseWords(s);

	cout << s<<endl;
}

int main()
{
	printTest("hhhh the sky is blue aaaaaaa");
	printTest(" ");
	printTest("     ");
	printTest(" a ");
	printTest("   a  ");
	printTest("  nice   guy   fucking   dick  ");
	printTest("nice   guy   fucking   dick  year");

	return 0;
}
