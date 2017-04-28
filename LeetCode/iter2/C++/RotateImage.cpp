#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        //横竖对半交换
        

        //根据对角线交换
    }
};

void testPrint(vector<vector<int>>& matrix)
{
    for(auto v:matrix)
    {
        for(int num:matrix)
            cout<<num<<" ";

        cout<<endl;
    }
}

int main(void)
{
    vector<int> v;


    cout<<"旋转矩阵前\n";
    testPrint(v);

    Solution s;

    s.rotate(v);

    cout<<"旋转矩阵后\n";
    testPrint(v);

	return 0;
}