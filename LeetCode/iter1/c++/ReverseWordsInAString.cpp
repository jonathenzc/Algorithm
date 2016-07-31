#include <iostream>
#include <string>

using namespace std;

//void reverseWords(string &s) {
//
//	//忽略开头的空格
//	int s_index = 0;
//	while(s_index < s.size())
//	{
//		if (s[s_index] != ' ')
//			break;
//		
//		s_index++;
//	}
//
//	//开头没有空格
//	if(s_index != 0)
//		s = s.substr(s_index);
//
//	//忽略结尾的空格
//	s_index = s.size()-1;
//	while (s_index >= 0)
//	{
//		if (s[s_index] != ' ')
//			break;
//
//		s_index--;
//	}
//
//	if (s_index != s.size() - 1)
//		s = s.substr(0,s_index+1);
//
//	//处理多余的空格
//	int firstSpaceIndex = -1;
//
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (s[i] == ' ')
//		{
//			if (firstSpaceIndex == -1)
//				firstSpaceIndex = i;
//		}
//		else
//		{
//			if (firstSpaceIndex != -1 && i - firstSpaceIndex != 1)
//			{
//				s = s.substr(0, firstSpaceIndex + 1) + s.substr(i);
//				i = firstSpaceIndex;
//			}
//
//			firstSpaceIndex = -1;
//		}
//	}
//
//	//反转字符串
//	int lastStart = -1, lastEnd = s.size(), start = 0, end = s.size()-1;
//	string head = "", tail = "";
//
//	while (start < end)
//	{
//		if (s[start] != ' ')
//		{
//			head += s[start];
//			start++;
//		}
//
//		if (s[end] != ' ')
//		{
//			tail = s[end]+tail;
//			end--;
//		}
//
//		if (s[start] == ' ' && s[end] == ' ')
//		{
//			if (lastStart == -1)
//				s = tail + s.substr(start,end-start+1) + head;
//			else
//				s = s.substr(0, lastStart+1)+tail + s.substr(start, end - start + 1) + head+s.substr(lastEnd);
//
//			start = lastStart + tail.size() + 2;
//			end = lastEnd - head.size() - 2;
//
//			lastStart = start-1;
//			lastEnd = end+1;
//			head = "";
//			tail = "";
//		}
//	}
//
//}


void reverse(string &str, int begin, int end) {
	while (begin < end) {
		char temp = str[begin];
		str[begin] = str[end];
		str[end] = temp;
		begin++;
		end--;
	}
}

//方法2:先翻转单词，再整体翻转整个字符串，需要处理多余的空格,比如Hello World先变成oellH dlroW
void reverseWords(string &s) {
	//忽略开头的空格，获取第一个非空格的开头
	int start = 0;
	while (start < s.size())
	{
		if (s[start] != ' ')
			break;

		start++;
	}

	//忽略结尾的空格,获取最后一个非空格的结尾
	int end = s.size() - 1;
	while (end >= 0)
	{
		if (s[end] != ' ')
			break;

		end--;
	}

	//方法是先翻转单词，再整体翻转整个字符串，需要处理多余的空格
	//
	int i = start;

	
	while (i <= end)
	{
		if (s[i] != ' ')
		{
			//找到该单词的结尾
			int j = i+1;
			while (j <= end && s[j] != ' ')
				j++;

			//翻转单词
			reverse(s,i,j-1);

			i = j;
		}
		else
		{
			//前一个不是空格，第一个空格
			if (s[i - 1] != ' ')
				i++;
			else
			{
				int j = i;
				//每次向前挪一个
				while (j < end)
				{
					s[j] = s[j + 1];
					j++;
				}

				end--;//挪一个
			}
		}
	}

	//翻转整个字符串
	reverse(s, start, end);

	s = s.substr(start,end-start+1);
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
