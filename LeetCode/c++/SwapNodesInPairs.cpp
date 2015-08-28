#include <iostream>

using namespace std;

struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* swapPairs(ListNode* head) {
	if(head == NULL || head->next == NULL)
		return head;
	
	ListNode *preNode = head; //指向A,B节点对中A的前一个节点
	ListNode *postNode = head->next; //指向A,B节点对中的节点B
	
	preNode->next = postNode->next;
	postNode->next = preNode;
	
	head = postNode; //重新记录开头节点
	
	while(preNode->next != NULL && preNode->next->next != NULL)
	{
		ListNode *nextHead = preNode->next;
		postNode = nextHead->next;
		
		//交换一对节点
		nextHead->next = postNode->next;
		postNode->next = nextHead;
		preNode->next = postNode;
		
		//设置前一个节点
		preNode = nextHead;
	}
	 
	return head;
}

int main()
{
	ListNode *root = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(4);	
	ListNode *node5 = new ListNode(5);
	ListNode *node6 = new ListNode(6);	
	
	root->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	
	root = swapPairs(root);
	
	while(root!=NULL)
	{
		cout<<root->val<<" ";
		root = root->next;
	}
	
	return 0;
}