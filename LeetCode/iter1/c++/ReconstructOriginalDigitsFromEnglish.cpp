#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <sstream>
#include <iomanip>
#include <queue>
#include <utility>

using namespace std;

void minusCnt(vector<int> &chCnt, string s,int cnt)
{
	for (char ch : s)
		chCnt[ch - 'a'] -= cnt;
}

string generateS(char ch, int cnt)
{
	string s = "";
	for (int i = 0; i < cnt; i++)
		s += ch;

	return s;
}

string originalDigits(string s) {
	vector<int> chCnt(26, 0);

	for (char ch : s)
		chCnt[ch-'a']++;

	int vIndex = 0;

	vector<string> strV(10,"");

	//处理zero z
	strV[0] = generateS('0',chCnt['z'-'a']);
	minusCnt(chCnt,"zero",chCnt['z'-'a']);

	//处理two w
	strV[2] = generateS('2', chCnt['w' - 'a']);
	minusCnt(chCnt, "two", chCnt['w' - 'a']);

	//处理four u
	strV[4] = generateS('4', chCnt['u' - 'a']);
	minusCnt(chCnt, "four", chCnt['u' - 'a']);

	//处理six x
	strV[6] = generateS('6', chCnt['x' - 'a']);
	minusCnt(chCnt, "six", chCnt['x' - 'a']);

	//处理eight g
	strV[8] = generateS('8', chCnt['g' - 'a']);
	minusCnt(chCnt, "eight", chCnt['g' - 'a']);

	//处理three h
	strV[3] = generateS('3', chCnt['h' - 'a']);
	minusCnt(chCnt, "three", chCnt['h' - 'a']);

	//处理five f
	strV[5] = generateS('5', chCnt['f' - 'a']);
	minusCnt(chCnt, "five", chCnt['f' - 'a']);

	//处理seven s
	strV[7] = generateS('7', chCnt['s' - 'a']);
	minusCnt(chCnt, "seven", chCnt['s' - 'a']);

	//处理one o
	strV[1] = generateS('1', chCnt['o' - 'a']);
	minusCnt(chCnt, "one", chCnt['o' - 'a']);

	//处理nine i
	strV[9] = generateS('9', chCnt['i' - 'a']);
	minusCnt(chCnt, "nine", chCnt['i' - 'a']);

	string ret = "";

	for (int i = 0; i < 10; i++)
		ret += strV[i];

	return ret;
}

int main()
{
	cout << originalDigits("owoztneoer") << endl;
	cout << originalDigits("fviefuro") << endl;

	return 0;
}