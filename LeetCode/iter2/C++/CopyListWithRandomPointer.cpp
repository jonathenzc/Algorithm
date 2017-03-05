#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>

using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL)
			return NULL;

		//获取待复制的列表中random指针在其列表中的位置
		unordered_map<RandomListNode*,int> pos_map;
		RandomListNode *headNext = head;
		int cnt = 0;

		while (headNext != NULL)
		{
			pos_map[headNext] = cnt;
			cnt++;
			headNext = headNext->next;
		}

		//构建复制顺序列表，未创建random指针
		RandomListNode *copyList = new RandomListNode(head->label);
		unordered_map<int, RandomListNode*> copy_pos_map;
		copy_pos_map[0] = copyList;

		RandomListNode *copyNext = copyList;
		headNext = head->next;
		cnt = 1;

		while (headNext != NULL)
		{
			RandomListNode *tmp = new RandomListNode(headNext->label);
			copy_pos_map[cnt] = tmp;
			copyNext->next = tmp;
			copyNext = copyNext->next;

			cnt++;
			headNext = headNext->next;
		}

		//更新random指针
		headNext = head;
		copyNext = copyList;
		while (headNext != NULL)
		{
			if (headNext->random == NULL)
				copyNext->random = NULL;
			else
				copyNext->random = copy_pos_map[pos_map[headNext->random]];

			headNext = headNext->next;
			copyNext = copyNext->next;
		}

		return copyList;
	}
};

int main(void)
{

	return 0;
}