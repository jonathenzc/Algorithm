class Solution:
    # @param {integer[]} nums
    # @return {integer[]}
    def productExceptSelf(self, nums):
        power = 1
        zeroCnt = 0
        for num in nums:
            if(num == 0):
                zeroCnt += 1
                if(zeroCnt == 2): #超过两个0的话整个数组都为0
                    power = 0
                    break
            else:		
                power *= num
								
        numsSize = len(nums)        
        if(power == 0):
            for i in range(numsSize):
                nums[i] = 0
        else:
            if(zeroCnt == 0):
                for i in range(numsSize):
                    nums[i] = power//nums[i]
            else:
                for i in range(numsSize):
                    if(nums[i] == 0):
                        nums[i] = power
                    else:
                        nums[i] = 0
			
        return nums
		
#测试程序
s = Solution()
nums = [1,0,3,5]
print(s.productExceptSelf(nums))					