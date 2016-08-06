#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	vector<int> v;
	int numsSize1 = nums1.size(), numsSize2 = nums2.size();
	int i = 0, j = 0;
	while (i < numsSize1 && j < numsSize2)
	{
		if (nums1[i] < nums2[j])
			v.push_back(nums1[i++]);
		else
			v.push_back(nums2[j++]);
	}

	if (i == numsSize1)
	{
		while (j < numsSize2)
			v.push_back(nums2[j++]);
	}
	else
	{
		while (i < numsSize1)
			v.push_back(nums1[i++]);
	}

	int wholeSize = numsSize1 + numsSize2;
	if (wholeSize & 1 == 1) //odd
		return v[wholeSize / 2];
	else
		return (v[wholeSize/2-1]+v[wholeSize/2])/2.0;
}

int main()
{
	vector<int> v1;
	vector<int> v2;
	v1.push_back(1);
	v1.push_back(3);


	v2.push_back(2);
	v2.push_back(4);

	cout<< findMedianSortedArrays(v1,v2);



	return 0;
}