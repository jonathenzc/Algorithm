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

	//solution 1: binary search each row
	bool searchMatrix1(vector<vector<int>>& matrix, int target) {
		bool ret = false;

		for (size_t i = 0; i < matrix.size(); i++)
		{
			ret = binarySearch(matrix[i], target);

			if (ret) {
				break;
			}
		}

		return ret;
	}

	//solution 2: binary search each row
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		bool ret = false;
		int i = matrix.size() - 1, j = 0;
		while (i >= 0 && j < matrix[0].size())
		{
			if (matrix[i][j] == target) {
				ret = true;
				break;
			}

			if (matrix[i][j] < target) {
				j++;
			}
			else {
				i--;
			}
		}

		return ret;
	}
private:
	bool binarySearch(vector<int>& rowMatrix, int target) {
		int start = 0, end = rowMatrix.size();
		bool ret = false;
		while (start < end) {
			int mid = (start + end) / 2;
			if (rowMatrix[mid] == target) {
				ret = true;
				break;
			}
			else if (rowMatrix[mid] < target) {
				start = mid + 1;
			}
			else {
				end = mid;
			}
		}

		return ret;
	}
};

void print(vector<vector<int>> v, int target) {
	Solution s;
	cout << target;
	if (s.searchMatrix(v, target)) {
		cout << " find\n";
	}
	else {
		cout << " not find\n";
	}
}

int main(void)
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(4);
	v1.push_back(7);
	v1.push_back(11);
	v1.push_back(15);

	vector<int> v2;
	v2.push_back(2);
	v2.push_back(5);
	v2.push_back(8);
	v2.push_back(12);
	v2.push_back(19);

	vector<int> v3;
	v3.push_back(3);
	v3.push_back(6);
	v3.push_back(9);
	v3.push_back(16);
	v3.push_back(22);

	vector<int> v4;
	v4.push_back(10);
	v4.push_back(13);
	v4.push_back(14);
	v4.push_back(17);
	v4.push_back(24);

	vector<int> v5;
	v5.push_back(18);
	v5.push_back(21);
	v5.push_back(23);
	v5.push_back(26);
	v5.push_back(30);

	vector<vector<int>> matrix;
	matrix.push_back(v1);
	matrix.push_back(v2);
	matrix.push_back(v3);
	matrix.push_back(v4);
	matrix.push_back(v5);

	print(matrix, 5);
	print(matrix, 20);

	return 0;
}