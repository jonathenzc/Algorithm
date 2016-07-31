class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def majorityElement(self, nums):
        halfNumSize = len(nums)
        if(halfNumSize == 1):
            return nums[0]
			
        halfNumSize //=2
        numDict = {}

        for num in nums:
            if num in numDict:
                numDict[num] += 1
                if(numDict[num] > halfNumSize):
                    return num
            else:
                numDict[num] = 1
		

#测试程序
nums = [1]
s = Solution()
print(s.majorityElement(nums))
