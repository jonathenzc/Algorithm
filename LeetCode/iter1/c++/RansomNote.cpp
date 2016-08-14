#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
	unordered_map<char, int> magazineMap;
	
	for (int i = 0; i < magazine.size(); i++)
		magazineMap[magazine[i]]++;

	bool result = true;

	for (int i = 0; i < ransomNote.size(); i++)
	{
		if (magazineMap[ransomNote[i]] == 0)
		{
			result = false;
			break;
		}
		else
			magazineMap[ransomNote[i]]--;
	}

	return result;
}

void testPrint(string a, string b)
{
	if (canConstruct(a, b))
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main()
{
	testPrint("a","b");
	testPrint("aa", "ab");
	testPrint("aa","aab");

	return 0;
}