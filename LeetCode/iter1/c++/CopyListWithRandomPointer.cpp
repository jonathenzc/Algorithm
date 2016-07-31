#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}	
};

RandomListNode *copyRandomList(RandomListNode *head) {
	if (head == NULL)
		return NULL;
	
	//记录原来链表与它在链表中第几个的映射
	map<RandomListNode*, int> pre_pos_map; //记录原链表和它是第几个的映射
	map<RandomListNode*, int> pre_random_pos_map; //记录该节点的随机节点时第几个的映射

	vector<RandomListNode*> v;
	RandomListNode *result = new RandomListNode(head->label);
	RandomListNode *resultTraverse = result;

	v.push_back(result);

	RandomListNode *tmp = head;
	int cnt = 1;
	pre_pos_map.insert(map<RandomListNode*, int>::value_type(tmp, cnt));
	tmp = tmp->next;

	while (tmp != NULL)
	{
		cnt++;
		RandomListNode *newNode = new RandomListNode(tmp->label);
		v.push_back(newNode);

		resultTraverse->next = newNode;
		resultTraverse = resultTraverse->next;

		pre_pos_map.insert(map<RandomListNode*, int>::value_type(tmp,cnt));
		tmp = tmp->next;

	}

	//记录随机的节点的位置哪个
	tmp = head;
	while (tmp != NULL)
	{
		RandomListNode* randomNode = tmp->random;
		if(randomNode == NULL)
			pre_random_pos_map.insert(map<RandomListNode*, int>::value_type(tmp, 0));
		else
			pre_random_pos_map.insert(map<RandomListNode*, int>::value_type(tmp, pre_pos_map[randomNode]));

		tmp = tmp->next;
	}

	//为新的节点指向随机节点
	tmp = head;
	resultTraverse = result;
	while (tmp != NULL)
	{
		RandomListNode* randomNode = tmp->random;
		if (randomNode == NULL)
			resultTraverse->random = NULL;
		else
			resultTraverse->random = v[pre_random_pos_map[tmp]-1];

		tmp = tmp->next;
		resultTraverse = resultTraverse->next;
	}


	return result;
}

int main()
{
	//RandomListNode* node1 = new RandomListNode(1);
	//RandomListNode* node2 = new RandomListNode(2);
	//RandomListNode* node3 = new RandomListNode(3);
	//RandomListNode* node4 = new RandomListNode(4);
	//RandomListNode* node5 = new RandomListNode(5);
	//RandomListNode* node6 = new RandomListNode(6);
	//RandomListNode* node7 = new RandomListNode(7);
	//RandomListNode* node8 = new RandomListNode(8);

	//node1->next = node2;
	//node2->next = node3;
	//node3->next = node4;
	//node4->next = node5;
	//node5->next = node6;
	//node6->next = node7;
	//node7->next = node8;

	//node1->random = node2;
	//node2->random = node3;
	//node3->random = node4;
	//node4->random = node5;
	//node5->random = node6;
	//node6->random = node7;
	//node7->random = node8;
	//node8->random = node8;

	RandomListNode* node1 = new RandomListNode(-1);
	RandomListNode* node2 = new RandomListNode(8);
	RandomListNode* node3 = new RandomListNode(7);
	RandomListNode* node4 = new RandomListNode(-3);
	RandomListNode* node5 = new RandomListNode(4);


	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;

	node1->random = node5;
	node2->random = node4;
	node3->random = NULL;
	node4->random = NULL;
	node5->random = node1;


	RandomListNode* result = copyRandomList(node1);

	cout <<"Finished" <<endl;

	return 0;
}
