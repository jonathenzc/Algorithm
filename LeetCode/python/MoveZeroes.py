class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        zeroCnt = 0
        arraySize = len(nums)
        for i in range(0,arraySize,1):
            if(nums[i] == 0):
                zeroCnt = zeroCnt+1
            else:
                nums[i-zeroCnt] = nums[i]
                
        for i in range(0,zeroCnt,1):
            nums[arraySize-zeroCnt+i] = 0
            
s = Solution()
a=[0,1,0,3,12]
s.moveZeroes(a)

print(a)        