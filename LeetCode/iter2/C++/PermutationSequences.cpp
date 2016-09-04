#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	Solution() {
		v.push_back(1);

		for (int i = 1; i <= 9; i++)
			v.push_back(v[i - 1] * i);
	}

	string getPermutation(int n, int k) {
		if (n == 0)
			return "";

		s = "";
		size = n;

		isUsed.clear();
		for (int i = 0; i <= size; i++)
			isUsed.push_back(false);

		helper(n,k);

		return s;
	}
private:
	vector<int> v;
	vector<int> isUsed;
	string s;
	int size;

	void helper(int n,int k)
	{
		if (n >= 1) {


			int firstNum = (k-1) / (v[n - 1]);
			int cnt = -1;
			for (int i = 1; i <= size; i++)
			{
				if (!isUsed[i]) {
					cnt++;
					if (cnt == firstNum) {
						s += char('0' + i);
						isUsed[i] = true;
						break;
					}
				}
			}

			helper(n - 1, ((k-1)%v[n - 1])+1);
		}
	}
};

int main()
{
	Solution s;
	
	for(int i=1;i<=24;i++)
		cout << s.getPermutation(4,i)<<endl;

	return 0;
}