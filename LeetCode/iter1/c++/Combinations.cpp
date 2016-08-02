#include <iostream>
#include <vector>

using namespace std;

//方法1：
//void helper(int index, int n, int k, vector<int> &curV, vector<vector<int>> &v)
//{
//	if (curV.size() == k)
//		v.push_back(curV);
//	else
//	{
//		for (int i = index+1; i <= n; i++)
//		{
//			curV.push_back(i);
//			helper(i,n,k,curV,v);
//			curV.pop_back();
//		}
//	}
//}
//
//vector<vector<int>> combine(int n, int k) {
//	vector<vector<int>> v;
//	vector<int> tmpV;
//
//	helper(0,n,k,tmpV,v);
//	
//	return v;
//}


//方法2：利用C(n,k) = C(n-1,k-1)+C(n-1,k)。第一个是指n这个数被选中了，那么只需要从n-1个中挑走k-1个；第二个是指n这个数没有被选中，那么需要从n-1个数中挑走k个
vector<vector<int>> combine(int n, int k) {
	if (k == 0 || k == n)
	{
		vector<vector<int>> v;
		vector<int> curV;
		for (int i = 0; i < k; i++)
			curV.push_back(i+1);

		v.push_back(curV);
		return v;
	}
	
	vector<vector<int>> v = combine(n-1,k-1); //选定n

	for (int i = 0; i < v.size(); i++)
		v[i].push_back(n);

	vector<vector<int>> tmpV = combine(n-1,k);
	for (auto innerV : tmpV)
		v.push_back(innerV);

	return v;
}

void testPrint(int n,int k)
{
	vector<vector<int>> v = combine(n,k);

	cout << "v Size " << v.size() << endl;

	for (auto innerV : v)
	{
		for (auto num : innerV)
			cout << num << " ";
		cout << endl;
	}

	cout << endl;
}

int main()
{
	testPrint(4,2);

	return 0;
}