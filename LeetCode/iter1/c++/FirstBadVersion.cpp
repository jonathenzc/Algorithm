#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int BADVERSION;

bool isBadVersion(int version)
{
	if (version >= BADVERSION)
		return true;
	else 
		return false;
}

int firstBadVersion(int n) {
	int start = 1, end = n;

	while (start < end)
	{
		int mid = start+(end - start) / 2; //切记，防止溢出
		 
		if (isBadVersion(mid))
			end = mid;
		else
		{
			if (start == end - 1)
				break;

			start = mid + 1;
		}
	}

	return end;
}

int main()
{
	int n = 25;

	for (int i = 1; i <= n; i++)
	{
		BADVERSION = i;
		cout << "i=" << i << " first bad version " << firstBadVersion(n)<<endl;
	}

	return 0;
}