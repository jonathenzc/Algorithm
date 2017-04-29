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
        for(int i=0;i<size/2;i++)
        {
            for(int j=0;j<size;j++)
            {
                swapValue(matrix[i][j],matrix[size-1-i][j]);
            }
        }

        //根据对角线交换
        for(int i=0;i<size;i++)
        {
            for(int j=i+1;j<size;j++)
            {
                swapValue(matrix[i][j],matrix[j][i]);
            }
        }
    }
private:
    void swapValue(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
};

void testPrint(vector<vector<int>>& matrix)
{
    for(auto v:matrix)
    {
        for(int num:v)
            cout<<num<<" ";

        cout<<endl;
    }
}

void vector_helper(int start,int step,vector<vector<int>> &v)
{
    vector<int> tmp;
    for(int i=0;i<step;i++)
        tmp.push_back(start+i);

    v.push_back(tmp);
}

int main(void)
{
    vector<vector<int>> v;
    int squareSize = 5;

    for(int i=0;i<squareSize;i++)
        vector_helper(i*squareSize,squareSize,v);

    cout<<"旋转矩阵前\n";
    testPrint(v);

    Solution s;

    s.rotate(v);

    cout<<"旋转矩阵后\n";
    testPrint(v);


	return 0;
}