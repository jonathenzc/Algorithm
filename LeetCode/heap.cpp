#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class heap {
public:
	//升序，构建最大堆
	void sortByAscend(vector<int>& v)
	{
		//从最后一排非叶子节点开始建堆 ()
		for (int i = v.size() / 2 - 1; i >= 0; i--)
			heapify(v, i, v.size());

		//从根节点开始调整堆
		for (int i = 0; i < v.size(); i++) {
			//将堆化数列中的最大值挪到数列的末尾
			int tmp = v[v.size() - 1 - i];
			v[v.size() - 1 - i] = v[0];
			v[0] = tmp;

			heapify(v, 0, v.size() - i);
		}
	}
private:
	//沿着子节点至上层父节点
	void heapify(vector<int>& v, int start, int size)
	{
		int child = start * 2 + 1;
		while (child < size)
		{
			if (child + 1 < size && v[child] < v[child + 1])
				child++;

			if (v[start] < v[child])
			{
				int tmp = v[child];
				v[child] = v[start];
				v[start] = tmp;
			}

			start = child;
			child = start * 2 + 1;
		}
	}
};

int main() {
	vector<int> v;
	for (int i = 10; i >= 0; i--) {
		v.push_back(i);
	}

	heap testHeap;
	testHeap.sortByAscend(v);

	for (int num : v)
		cout << num << " ";
}
