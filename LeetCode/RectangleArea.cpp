#include <iostream>
#include <math.h>

using namespace std;

int rectangleLength(int D,int H, int B,int F)
{
	int shadowLength = 0;

	if (D > H)//����1�����ھ���2��������
	{
		if (B > F && B < H)
			shadowLength = abs(H - B);
		else if (B <= F)
			shadowLength = abs(H - F);
	}
	else//����1�����ھ���2��������
	{
		if (B > F && B < H)
			shadowLength = abs(D - B);
		else if (B <= F)
			shadowLength = abs(D - F);
	}

	return shadowLength;
}

//�����������֮�ͼ�ȥ��Ӱ���
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
{
	int recArea1 = abs((C-A)*(D-B));
	int recArea2 = abs((G-E)*(H-F));
	int shadowArea = 0;
	int shadowLength = 0;
	int shadowWidth = 0;

	//�ȴ���������2���������ҵ�
	if (D <= F)
		shadowArea = 0;
	else if (B >= H)
		shadowArea = 0;
	else if (C <= E)
		shadowArea = 0;
	else if (A >= G)
		shadowArea = 0;
	else if (A < E)//1�������2�����
	{
		if (C <= G)//����1���ұ��ھ���2���м�
		{
			shadowWidth = abs(C - E);
			shadowLength = rectangleLength(D,H,B,F);

		}
		else//����1���ұ��ھ���2���ұ�
		{
			shadowWidth = abs(G - E);
			shadowLength = rectangleLength(D, H, B, F);
		}
	}
	else if (A>=E && A<G)//����1������ھ���2���м�
	{
		if (C<=G)//����1���ұ��ھ���2���м�
		{
			shadowWidth = abs(C - A);
			shadowLength = rectangleLength(D, H, B, F);
		}
		else//����1���ұ��ھ���2���ұ�
		{
			shadowWidth = abs(G - A);
			shadowLength = rectangleLength(D, H, B, F);
		}
	}

	shadowArea = shadowLength * shadowWidth;

	return recArea1 + recArea2 - shadowArea;
}

int main()
{
	int A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2;
	cout << computeArea(A,B,C,D,E,F,G,H);

	return 0;
}