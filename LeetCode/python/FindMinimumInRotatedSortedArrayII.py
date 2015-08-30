class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        preNum = nums[0]
        numsSize = len(nums)
        for i in range(1,numsSize,1):
            if(nums[i] >= preNum):
                preNUm = nums[i]
            else:
                return nums[i]
                
        return nums[0]    
			
#测试程序
s = Solution()
nums = [0,1,2,3,4,5,6,7]
print(s.findMin(nums))
