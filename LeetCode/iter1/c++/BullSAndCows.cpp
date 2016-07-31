#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

string int2Str(int a)
{
	stringstream ss;
	ss << a;
	string s;
	ss >> s;

	return s;
}

string getHint(string secret, string guess) {
	if (secret == "")
		return "0A0B";

	//为secret构建一个map
	int *map = new int[10];
	for (int i = 0; i < 10; i++)
		map[i] = 0;

	for (int i = 0; i < secret.size(); i++)
		map[secret[i]-'0']++;

	int bullCnt = 0, cowCnt = 0;
	for (int i = 0; i < secret.size(); i++)
	{
		if (secret[i] == guess[i])
		{
			bullCnt++;
			map[guess[i] - '0']--;
		}
		else
		{
			if (map[guess[i] - '0']>0)
			{
				cowCnt++;
				map[guess[i] - '0']--; //已经被用过了
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (map[i] < 0)
		{
			cowCnt += map[i];
		}
	}

	string s = "";
	s = int2Str(bullCnt) + "A" + int2Str(cowCnt) + "B";

	return s;
}


int main()
{
	cout << getHint("1123","0111")<<endl; //1A1B
	cout << getHint("1807", "7810") << endl; //1A3B
	cout << getHint("1234", "4321") << endl; //0A4B
	cout << getHint("1110", "0111") << endl; //2A2B
	cout << getHint("", "") << endl;         //0A0B
	cout << getHint("1230", "0111") << endl; //0A2B
	cout << getHint("1130", "0111") << endl; //1A2B
	cout << getHint("1122", "2211") << endl; //0A4B
	cout << getHint("1122", "1122") << endl; //4A0B
	cout << getHint("1122", "1222") << endl; //3A0B 
	cout << getHint("1122", "1221") << endl; //2A2B 
	return 0;
}