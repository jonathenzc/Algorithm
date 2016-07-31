class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        end= len(nums)-1
        start = 0
        while(start<end):
            mid = (start+end)//2
            if(nums[mid] > nums[end]):
                start = mid+1
            else:
                end = mid
            
        return nums[start]
        
#测试程序
s = Solution()
nums = [4,5,6,7,0,1,2,3]
print(s.findMin(nums))