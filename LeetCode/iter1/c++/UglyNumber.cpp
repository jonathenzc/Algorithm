#include <iostream>
#include <math.h>

using namespace std;

//��num����n������
int degrade(int num,int n)
{
	while (num % n == 0)
		num = num / n;

	return num;
}

bool isUgly(int num) {
	if (num <= 0)
		return false;

	//���һ�����������⣬��ô�������Ա�ʾ��2^l * 3^m * 5^n
	//����2������
	num = degrade(num, 2);

	//����3������
	num = degrade(num, 3);

	//����5������
	num = degrade(num, 5);

	//��������Ϊ1�Ļ����Ͳ���ugly��
	if (num != 1)
		return false;
	else
		return true;
}

int main()
{
	if (isUgly(6)) //Yes
		cout << "Yes\n";
	else
		cout << "No\n";

	if (isUgly(8)) //Yes
		cout << "Yes\n";
	else
		cout << "No\n";

	if (isUgly(14)) //No
		cout << "Yes\n";
	else
		cout << "No\n";

	if (isUgly(1)) //Yes
		cout << "Yes\n";
	else
		cout << "No\n";

	if (isUgly(17)) //No
		cout << "Yes\n";
	else
		cout << "No\n";

	if (isUgly(28)) //No
		cout << "Yes\n";
	else
		cout << "No\n";

	return 0;
}