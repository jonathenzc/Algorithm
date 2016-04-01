#include <iostream>
#include <vector>
#include <map>

using namespace std;

//struct sumPair
//{
//	int value;
//	int index;
//};
//
//vector<int> twoSum(vector<int>& nums, int target) 
//{
//	vector<int> resultI;
//	map<int, sumPair> m;
//
//	for (int i = 0; i < nums.size(); i++)
//	{
//		sumPair pair;
//		if (m.find(nums[i]) == m.end())
//		{
//			pair.value = target-nums[i];
//			pair.index = i;
//		}
//		else
//		{
//			if (target - nums[i] == nums[i])
//			{
//				resultI.push_back(m[nums[i]].index);
//				resultI.push_back(i);
//				break;
//			}
//		}
//
//		m.insert(map<int,sumPair>::value_type(nums[i],pair));
//	}
//
//	if (resultI.size() == 0)
//	{
//		for (int i = 0; i < nums.size(); i++)
//		{
//			int pairValue = m[nums[i]].value;
//			
//			if (pairValue != nums[i])
//			{
//				if (m.find(pairValue) != m.end())
//				{
//					resultI.push_back(m[nums[i]].index);
//					resultI.push_back(m[pairValue].index);
//					break;
//				}
//			}
//		}
//	}
//
//	return resultI;
//}

vector<int> twoSum(vector<int>& nums, int target) 
{
	vector<int> resultI;
	map<int, int> m;

	for (int i = 0; i < nums.size(); i++)
	{

		if (m.find(target - nums[i]) == m.end())
		{
			m.insert(map<int, int>::value_type(nums[i], i));
		}
		else
		{
			resultI.push_back(m[target - nums[i]]);
			resultI.push_back(i);
			break;
		}
	}

	return resultI;
}

//vector<int> twoSum(vector<int>& nums, int target)
//{
//	std::unordered_map<int, int> num2id;
//	for (int i = 0; i < nums.size(); i++)
//	{
//		int res = target - nums[i];
//		auto it = num2id.find(res);
//		if (it != num2id.end()) return vector<int>{it->second, i};
//		num2id[nums[i]] = i;
//	}
//
//	return vector<int>();
//}

int main()
{
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(5);
	nums.push_back(2);

	vector<int> resultV;
	resultV = twoSum(nums, 4);
	for (int i = 0; i < resultV.size(); i++)
		cout << resultV[i] << " ";

	return 0;
}