#include <iostream>

using namespace std;

//��ȡһ�볤�ȵ�����ת����int������һ����������бȽ�
bool isPalindrome(int x) 
{
	if (x < 0 || (x!=0 && x%10==0))//������Ϊ���������߽�βΪ0�Ҹ�����Ϊ0������Ҳ��Ϊ����
		return false;

	int halfInt = 0;

	while (halfInt < x)
	{
		halfInt *= 10;
		halfInt += x % 10;
		x = x / 10;
	}

	if (x == halfInt)
		return true;
	else
	{
		if (halfInt / 10 == x)//����12321,������������halfInt����123,��x����12
			return true;
		else
			return false;
	}
}

int main()
{
	if (isPalindrome(1))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}