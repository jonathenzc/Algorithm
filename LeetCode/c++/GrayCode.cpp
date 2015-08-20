#include <iostream>
#include <vector>

using namespace std;

vector<int> grayCode(int n) 
{
	vector<int> v;
	v.push_back(0);

	if (n == 0)
		return v;

	v.push_back(1);

	for (int i = 1; i < n; i++)
	{
		//����Ҫ�ӵ�2������
		int addition = 1;
		int cnt = 0;
		while (cnt < i)
		{
			addition *= 2;
			cnt++;
		}

		//��������ʼ���������
		int nextGrayCode;
		for (int j = addition - 1; j >= 0; j--) //��2���ݵ�0����addition
		{
			nextGrayCode = v[j] + addition;
			v.push_back(nextGrayCode);
		}
	}

	return v;
}

int main()
{
	vector<int> v;
	v = grayCode(0);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return 0;
}