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
	bool judgeCircle(string moves) {
		int UDCnt = 0, LRCnt = 0;
		for (int i = 0; i < moves.size(); i++)
		{
			if (moves[i] == 'R')
				LRCnt++;
			else if (moves[i] == 'L')
				LRCnt--;
			else if (moves[i] == 'U')
				UDCnt++;
			else if (moves[i] == 'D')
				UDCnt--;
		}

		if (UDCnt == 0 && LRCnt == 0)
			return true;
		else
			return false;
	}
};

void testPrint(string moves)
{
	Solution ss;
	if (ss.judgeCircle(moves))
		cout << moves << " Can move back\n";
	else
		cout << moves << " Can not move back\n";
}

int main(void)
{
	testPrint("LR");
	testPrint("LL");
	testPrint("RR");
	testPrint("UD");



	return 0;
}