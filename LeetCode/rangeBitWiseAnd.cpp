#include <iostream>
#include <string>

using namespace std;

//��������ת�ɶ�����
string intToBinary(int num)
{
	string s = "";

	while (num != 0)
	{
		s += num % 2 + '0';
		num = num / 2;
	}

	return s;
}

int rangeBitWiseAnd(int m,int n)
{
	string mStr = intToBinary(m);
	string nStr = intToBinary(n);

	if (mStr.size() != nStr.size())
		return 0;
	else
	{
		//��¼�����ַ�����һ����ͬ������±�����
		//�ҵ���һ����ͬ���±��������������أ���¼��һ���±���ͬ���±�
		int lastEqualPos = mStr.size() - 1;
		for (int i = mStr.size() - 2; i >= 0; i--)
		{
			if (mStr[i] != nStr[i])
				break;
			else
			{
				if (mStr[i] == '1')
					lastEqualPos = i;
			}
		}

		//
		int wiseAndResult=0;

		for (int i = lastEqualPos; i < mStr.size(); i++)
		{
			//�����ַ����е�λ�õó���λ�õĶ����ݣ�����iΪ2������2^2
			//������ʵ��math�����pow�Ϳ�����
			if (mStr[i] == '1')
			{
				int cnt = 0;
				int power = 1;//���η��Ľ��
				while (cnt < i)
				{
					power *= 2;
					cnt++;
				}

				wiseAndResult += power;
			}
		}

		return wiseAndResult;
	}
}

int main()
{
	cout << rangeBitWiseAnd(2,2)<<endl;

	return 0;
}