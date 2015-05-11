#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) 
{
	if (s.size() == 0 || s.size() == 1)
		return true;
	else
	{
		//�Ƚ�ԭ�ַ����Ŀո����������ĸ�������ַ�ȥ����������д��ĸת��ΪСд��ĸ
		string newS = "";
		for (int i = 0; i < s.size(); i++)
		{
			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
				newS += s[i];
			else if (s[i] >= 'A' && s[i] <= 'Z')
				newS += s[i]+32;
		}
		
		//��Ԥ�������ַ������˷ֱ�����ָ�����Ƚ��Ƿ�Ϊ����
		//cout << newS << endl;

		int head = 0,tail = newS.size()-1;
		bool result = true;

		while (head <= tail)
		{
			if (newS[head] != newS[tail])
			{
				result = false;
				break;
			}

			head++;
			tail--;
		}

		return result;
	}
}

int main()
{
	if (isPalindrome("1a2"))
		cout << "True";
	else
		cout << "False";

	return 0;
}