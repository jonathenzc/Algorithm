#include <iostream>
#include <vector>

using namespace std;

//nums��������С�ر�󣬿�������m+n�Ĵ�С����һ��ʼ��˼ά���鲢�����ˣ�ֻ����Ū���µĿռ䣬������ָ��ֱ�ָ��nums1��nums2,Ȼ����ݴ�С�����롣
//��ʵ���Ͽ��ԴӺ��濪ʼ�����в���
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
	int index = m + n - 1;
	int i = m - 1;//��nums1�����ʼ����
	int j = n - 1;//��nums2�����ʼ����

	//�����и����ɣ���Ϊ������Ҫ��nums2��Ԫ���Ƶ�nums1�У���ônums2�е�Ԫ�ؿ϶���Ҫ�����ߵģ�����ѭ��������������j>=0
	//���nums1��Ԫ��ȫûʱ������ָm��Ԫ�أ�,nums2����Ԫ��,��������ֻ��Ҫ��nums2�е�Ԫ���Ƶ�nums1,����ѭ���е�if�ж���Ҫ�Ӹ�i>=0������һ�¡�
	while (j>=0)
	{
		if (i>=0 && nums1[i] > nums2[j])
			nums1[index--] = nums1[i--];
		else
			nums1[index--] = nums2[j--];
	}
}

int main()
{
	return 0;
}