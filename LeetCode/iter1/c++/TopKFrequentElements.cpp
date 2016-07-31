#include <iostream>
#include <vector>
#include <map>

using namespace std;
	
struct elePair
{
	int frequency;
	int num;
};

int partition(vector<elePair>& nums,int start,int end)
{
	elePair target = nums[start];
	int j = start;

	for (int i = start+1; i <= end; i++)
	{
		if (nums[i].frequency <= target.frequency)
		{
			j++;
			elePair tmp = nums[j];
			nums[j] = nums[i];
			nums[i] = tmp;
		}
	}

	elePair tmp = nums[j];
	nums[j] = target;
	nums[start] = tmp;

	return j;
}

int getKthPivot(vector<elePair>& nums, int start, int end,int k)
{
	int pivot = partition(nums,start,end);

	int diff = end - pivot +1;

	if (k == diff)
		return end+1-k;
	else if (k > diff)
		return getKthPivot(nums, start, pivot - 1, k-diff);
	else
		return getKthPivot(nums,pivot+1,end,k);
}

vector<int> findKthLargest(vector<elePair>& nums, int k) {
	int vSize = nums.size()-1;
	
	int pivot = getKthPivot(nums,0,vSize,k);

	vector<int> v;
	for (int i = vSize; i >= pivot; i--)
		v.push_back(nums[i].num);

	return v;
}

vector<int> topKFrequent(vector<int>& nums, int k) 
{
	map<int, int> numFre;

	//利用map统计数列中数出现的频率
	for (int i = 0; i < nums.size(); i++)
	{
		if (numFre.find(nums[i]) == numFre.end())
			numFre.insert(map<int, int>::value_type(nums[i], 1));
		else
			numFre[nums[i]]++;
	}

	//将map中的数塞入vector中
	vector<elePair> v;
	map<int, int>::iterator iter;
	for (iter = numFre.begin(); iter != numFre.end(); iter++)
	{
		elePair pair;
		pair.frequency = iter->second;
		pair.num = iter->first;

		v.push_back(pair);
	}

	//利用求第k大的数的方法来求
	vector<int> result = findKthLargest(v,k);

	return result;
}

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(3);

	vector<int> v = topKFrequent(nums,2);
	for (int i = 0; i < v.size();i++)
	{
		cout << nums[i] << " ";
	}

	return 0;
}
