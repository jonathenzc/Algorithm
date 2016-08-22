#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string postOrder(string a, string b)
{
	if (a.size() < 2)
		return a;
	else 
	{
		char root = a[0];
		int rootIndex = b.find(root);

		string leftPreStr = b.substr(0,rootIndex);
		string rightPreStr = b.substr(rootIndex+1);

		string leftInStr = a.substr(1,rootIndex);
		string rightInStr = a.substr(rootIndex+1);

		string leftPostStr = postOrder(leftInStr,leftPreStr);
		string rightPostStr = postOrder(rightInStr,rightPreStr);

		return leftPostStr + rightPostStr + root;
	}
}

int main()
{
	string a, b;
	
	cin >> a >> b;

	cout << postOrder(a,b);

	return 0;
}