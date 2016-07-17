#include <iostream>

using namespace std;

int target = 1702766719;

int guess(int num)
{
	if (num == target)
		return 0;
	else if (num > target)
		return -1;
	else
		return 1;
}

int guessNumber(int n) {
	long long start = 1;
	long long end = n;
	long long mid = n;

	while (start <= end)
	{
		mid = (start + end) / 2;

		int result = guess(mid);
		if (result == 0)
			break;
		else if (result == -1)
			end = mid - 1;
		else if (result == 1)
			start = mid + 1;
	}

	return mid;
}

int main()
{
	cout << guessNumber(2126753390)<<endl;

	return 0;
}