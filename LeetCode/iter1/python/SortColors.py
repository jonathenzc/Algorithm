class Solution(object):
    def arrangeColors(self, nums,start,end,value):
        """
        :type nums: List[int]
        :type start: integer
        :type end: integer
        :type value: integer
        :rtype: void Do not return anything, modify nums in-place instead.
        """    
        for i in range(start,end,1):
            nums[i] = value     
    
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        zeroCnt = 0
        oneCnt = 0
        twoCnt = 0
        #统计012出现的次数
        for i in nums:
            if(i == 0):
                zeroCnt += 1
            elif(i == 1):
                oneCnt += 1
            elif(i==2):
                twoCnt += 1
        
        #根据次数重新分配012
        self.arrangeColors(nums,0,zeroCnt,0)
        self.arrangeColors(nums,zeroCnt,zeroCnt+oneCnt,1)
        self.arrangeColors(nums,zeroCnt+oneCnt,zeroCnt+oneCnt+twoCnt,2)
        
#测试程序
s = Solution()
num = [0,1,1,1,0,0,0,0,2,2,2,2]
s.sortColors(num)
print(num)