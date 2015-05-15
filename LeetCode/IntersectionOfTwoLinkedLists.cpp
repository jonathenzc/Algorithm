#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//因为题设中说两个链表都没有环，如果两个链表相交，那么它们从相交之后的节点都是相同的。
//故我们判断的方法就是只需要判断两个链表的最后一个节点是否相同即可
//当然题目需要我们返回第一个相交的节点，那么可以记录链表的长度
//接着将那个长度较长的链表减去两链表长度之差
//比如：
//A:        a1 → a2
//	                ↘
//	                 c1 → c2 → c3
//	                ↗
//B : b1 → b2 → b3
//调整链表B从b2开始访问

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
	int listASize = 0;
	int listBSize = 0;

	//获取第一个链表的最后一个元素
	ListNode *lastHeadA = headA;
	while (lastHeadA != NULL)
	{
		lastHeadA = lastHeadA->next;
		listASize++;
	}

	//获取第二个链表的最后一个元素
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

		//将更长的链表往前挪两链表长度之差个节点
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