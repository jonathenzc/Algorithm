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
	//brute force O(nlogn)
	int rotatedDigitsBruteForce(int N) {
		int ret = 0;

		for (int i = 1; i <= N; i++) {
			if (judge(i))
				ret++;
		}

		return ret;
	}

	//O(log N) http://www.frankmadrid.com/ALudicFallacy/2018/02/28/rotated-digits-leet-code-788/
	int rotatedDigits(int N) {
		string s = str2int(N);

		return rotateHelper(s, 0, false);;
	}
private:
	//                   0 1 2 3 4 5 6 7 8 9
	int numberState[10]{ 0,0,1,2,2,1,1,2,0,1 }; //0(same) 1(new number) 2(invalid)
	int newNumber[10]{   0,0,1,1,1,2,3,3,3,4 }; //2 5 6 9是new number
	int validNumber[10]{ 1,2,3,3,3,4,5,5,6,7 };  //3 4 7是invalid
	int sameNumber[10]{  1,2,2,2,2,2,2,2,3,3 }; //0 1 8

	bool judge(int N) {
		bool ret = false;
		string s = str2int(N);
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '3' || s[i] == '4' || s[i] == '7') {
				ret = false;
				break;
			}

			if (s[i] == '2' || s[i] == '5' || s[i] == '6' || s[i] == '9') {
				ret = true;
			}
		}

		return ret;
	}

	string str2int(int N) {
		stringstream ss;
		ss << N;

		string ret;
		ss >> ret;

		return ret;
	}

	int rotateHelper(string s, int index, bool isNewNumber) {
		int num = s[index] - '0', ret = 0;
		if (index == s.size() - 1) {
			if (isNewNumber) //前一个数是2 5 6 9，则用valid
				return validNumber[num];
			else
				return newNumber[num];
		}

		if (num > 0) {
			ret += validNumber[num - 1] * pow(7, s.size() - index - 1);

			if (!isNewNumber) //不是新数，就需要减去
				ret -= sameNumber[num - 1] * pow(3, s.size() - index - 1);
		}

		if (numberState[num] == 1) //new number
			isNewNumber = true;

		if (numberState[num] != 2) {
			ret += rotateHelper(s, index + 1, isNewNumber);
		}

		return ret;
	}
};

int main(void)
{
	Solution s;

	//for (int i = 1; i < 20; i++) {
	//	cout << i << " " << s.rotatedDigits(i) << endl;
	//}

	cout << s.rotatedDigits(25) << endl;
	cout << s.rotatedDigits(100) << endl;
	cout << s.rotatedDigits(1000) << endl;
	cout << s.rotatedDigits(500) << endl;
	cout << s.rotatedDigits(5000) << endl;

	return 0;
}