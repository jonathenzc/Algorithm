#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		string ret = "";

		//构建一个每个位数的9个数的二维数组
		string alphabat[4][10] = { 
			{"","I","II","III","IV","V","VI","VII","VIII","IX" },
			{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" },
			{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" },
			{"","M","MM","MMM"} 
		};
		
		ret += alphabat[3][num / 1000];//千位数
		num = num % 1000;

		ret += alphabat[2][num / 100];//百位数
		num = num % 100;

		ret += alphabat[1][num / 10];//十位数
		num = num % 10;

		ret += alphabat[0][num / 1];//个位数

		return ret;
	}
};


int main(void)
{
	Solution s;
	cout << s.intToRoman(3999)<<endl;

	return 0;
}