class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        numSize = len(nums)
        numSum = (numSize+1)*(numSize)//2
		
        for num in nums:
            numSum -= num
			
        return numSum
				
				
#测试程序
s = Solution()
nums = [0]

print(s.missingNumber(nums))