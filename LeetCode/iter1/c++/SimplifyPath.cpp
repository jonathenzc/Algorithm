#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

//方法一：
//string pathHelper(stack<string> st)
//{
//	string s="";
//
//	stack<string> newSt;
//
//	while (!st.empty())
//	{
//		string tmp = st.top();
//		st.pop();
//		newSt.push(tmp);
//	}
//
//	while (!newSt.empty())
//	{
//		string tmp = newSt.top();
//		newSt.pop();
//		s += '/'+tmp;
//	}
//
//	if (s.size() == 0)
//		s = "/";
//
//	return s;
//}
//
//string simplifyPath(string path) {
//	if (path.size() == 0)
//		return path;
//	
//	stack<string> st;
//
//	string dir = "";
//	int dotCnt = 0; //一个点发现
//	bool isSlashFound = false; //是否已经出现过slash
//
//	for (int i = 1; i < path.size(); i++)
//	{
//		if (path[i] == '/')
//		{
//			if (dotCnt == 2) //第二次点
//			{
//				if (!st.empty())
//					st.pop();
//			}
//
//			if (!isSlashFound)
//			{
//				isSlashFound = true;
//
//				if (dotCnt > 2)
//				{
//					for (int i = 0; i < dotCnt; i++)
//						dir += '.';
//				}
//
//				if(dir.size() != 0)
//					st.push(dir);
//			}
//
//			dir = "";
//			dotCnt = 0;
//		}
//		else if (path[i] == '.')
//		{
//			if (dir.size() != 0)
//				dir += '.';
//			else
//				dotCnt++;
//		}
//		else
//		{
//			for (int i = 0; i < dotCnt; i++)
//				dir += '.';
//
//			dir += path[i];
//			isSlashFound = false;
//			dotCnt = 0;
//		}
//	}
//
//	if (dir.size() != 0) //处理/abc/与/abc这样的情况
//		st.push(dir);
//
//	if (dotCnt > 2)
//	{
//		string dotStr = "";
//		for (int i = 0; i < dotCnt; i++)
//			dotStr += '.';
//
//		st.push(dotStr);
//	}
//	else if (dotCnt == 2)
//	{
//		if (!st.empty())
//			st.pop();
//	}
//
//
//	//将栈中的元素转化成字符串
//	string result = pathHelper(st);
//
//	return result;
//}

//方法2：
vector<string> split(string path,char c)
{
	vector<string> v;
	if (path.size() == 0)
		return v;

	int index = 0,nextIndex=0;
	while (index < path.size())
	{
		nextIndex = path.find(c,index+1);
		string substr = path.substr(index+1,nextIndex-index-1);
		v.push_back(substr);

		index = nextIndex;
	}

	return v;
}

string simplifyPath(string path) {
	vector<string> splitV = split(path,'/');
	vector<string> storedV;

	for (auto dir : splitV)
	{
		if(dir.compare("") == 0 || dir.compare(".") == 0)//空和.就忽略
		{}
		else if (dir.compare("..") == 0)
		{
			if (!storedV.empty())
				storedV.pop_back();
		}
		else
			storedV.push_back(dir);
	}

	string returnStr = "";
	for (auto str : storedV)
		returnStr += "/" + str;

	if (returnStr.size() == 0)
		returnStr = "/";

	return returnStr;
}

void testPrint(string s)
{
	vector<string> v = split(s,'/');
	for (auto word : v)
		cout << word << endl;
}

int main()
{
	cout << simplifyPath("/a/./b/c/")<<endl;
	cout << simplifyPath("/a/../b/c/") << endl;
	cout << simplifyPath("/../") << endl;
	cout << simplifyPath("/") << endl;
	cout << simplifyPath("//") << endl;
	cout << simplifyPath("/./") << endl;
	cout << simplifyPath("/") << endl;
	cout << simplifyPath("//") << endl;
	cout << simplifyPath("/home/") << endl;
	cout << simplifyPath("/home") << endl;
	cout << simplifyPath("/home//abc") << endl;
	cout << simplifyPath("/home//") << endl;
	cout << simplifyPath("/a/./b/../../c/") << endl;
	cout << simplifyPath("/../../") << endl;
	cout << simplifyPath("/../.././abc/cde") << endl;
	cout << simplifyPath("/...") << endl;
	cout << simplifyPath("/.../") << endl;
	cout << simplifyPath("/...a") << endl;
	cout << simplifyPath("/...a../fdsa./") << endl;
	cout << simplifyPath("/...a../fdsa../") << endl;
	cout << simplifyPath("/...a../fdsa..asdf..fdsa/") << endl;
	cout << simplifyPath("/...a../fdsa..asdf...fdsa./") << endl;

	cout << simplifyPath("/abc/...") << endl;
	cout << simplifyPath("/...hidden") << endl;
	cout << simplifyPath("/..edf") << endl;
	cout << simplifyPath("/.edf") << endl;
	cout << simplifyPath("/.") << endl;
	cout << simplifyPath("/..") << endl;
	cout << simplifyPath("/../") << endl;
	cout << simplifyPath("///TJbrd/owxdG//") << endl;
	cout << simplifyPath("///eHx/..") << endl;
	cout << simplifyPath("///eHx/../") << endl;


	return 0;
}
