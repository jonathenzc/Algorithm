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

// Employee info
class Employee {
public:
	// It's the unique ID of each node.
	// unique id of this employee
	int id;
	// the importance value of this employee
	int importance;
	// the id of direct subordinates
	vector<int> subordinates;
};

class Solution {
public:
	int getImportance(vector<Employee*> employees, int id) {
		//构建id与员工对象的映射
		unordered_map<int, Employee*> id2Employee;
		for (int i = 0; i < employees.size(); i++) {
			Employee* employee = employees[i];
			id2Employee[employee->id] = employee;
		}

		//通过队列遍历员工层级关系
		Employee* topEmployee = id2Employee[id];
		int importanceSum = topEmployee->importance;
		queue<vector<int>> q;
		q.push(topEmployee->subordinates);

		while (!q.empty()) {
			vector<int> subordinateV = q.front();
			q.pop();

			for (int i = 0; i < subordinateV.size(); i++) {
				int id = subordinateV[i];
				Employee* tmpEmployee = id2Employee[id];

				importanceSum += tmpEmployee->importance;
				q.push(tmpEmployee->subordinates);
			}
		}

		return importanceSum;
	}
};

int main(void)
{
	vector<Employee*> v;
	Employee employee1;
	employee1.id = 1;
	employee1.importance = 10;
	vector<int> subordinates1;
	subordinates1.push_back(2);
	employee1.subordinates = subordinates1;

	Employee employee2;
	employee2.id = 2;
	employee2.importance = 3;
	vector<int> subordinates2;
	/*subordinates2.push_back(3);*/
	employee2.subordinates = subordinates2;

	Employee employee3;
	employee3.id = 3;
	employee3.importance = 11;
	vector<int> subordinates3;
	employee3.subordinates = subordinates3;

	v.push_back(&employee1);
	v.push_back(&employee2);
	v.push_back(&employee3);

	Solution s;

	cout << s.getImportance(v,1) <<endl;

	return 0;
}