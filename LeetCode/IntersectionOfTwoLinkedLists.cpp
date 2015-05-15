#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//��Ϊ������˵��������û�л���������������ཻ����ô���Ǵ��ཻ֮��Ľڵ㶼����ͬ�ġ�
//�������жϵķ�������ֻ��Ҫ�ж�������������һ���ڵ��Ƿ���ͬ����
//��Ȼ��Ŀ��Ҫ���Ƿ��ص�һ���ཻ�Ľڵ㣬��ô���Լ�¼����ĳ���
//���Ž��Ǹ����Ƚϳ��������ȥ��������֮��
//���磺
//A:        a1 �� a2
//	                �K
//	                 c1 �� c2 �� c3
//	                �J
//B : b1 �� b2 �� b3
//��������B��b2��ʼ����

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
	int listASize = 0;
	int listBSize = 0;

	//��ȡ��һ����������һ��Ԫ��
	ListNode *lastHeadA = headA;
	while (lastHeadA != NULL)
	{
		lastHeadA = lastHeadA->next;
		listASize++;
	}

	//��ȡ�ڶ�����������һ��Ԫ��
	ListNode *lastHeadB = headB;
	while (lastHeadB != NULL)
	{
		lastHeadB = lastHeadB->next;
		listBSize++;
	}

	ListNode *resultNode = NULL;

	if (lastHeadA == lastHeadB)
	{
		lastHeadA = headA;
		lastHeadB = headB;

		//��������������ǰŲ��������֮����ڵ�
		if (listASize > listBSize)
		{
			for (int i = 0; i < (listASize - listBSize); i++)
				lastHeadA = lastHeadA->next;
		}
		else if (listASize < listBSize)
		{
			for (int i = 0; i < (listBSize - listASize); i++)
				lastHeadB = lastHeadB->next;
		}

		while (lastHeadA != lastHeadB)
		{
			lastHeadA = lastHeadA->next;
			lastHeadB = lastHeadB->next;
		}

		resultNode = lastHeadA;
	}
	
	return resultNode;
}

int main()
{
	return 0;
}