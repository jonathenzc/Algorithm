class Solution:
    # @param {integer} start
    # @param {integer} end
    # @return {void}
    def addRange(self,start,end):
        rangeStr = str(start)
        if(end != start): #范围的起始和结尾整数不同
            rangeStr += "->"+str(end)
            
        self.resultRange.append(rangeStr)
                    
    # @param {integer[]} nums
    # @return {string[]}
    def summaryRanges(self, nums):
        if(len(nums) == 0):
            return []

        self.resultRange = [] #返回的范围列表
        startInt = nums[0] #范围的起始整数
        endInt = nums[0] #范围的结束整数
            
        for i in range(1,len(nums)):
            if(endInt+1 < nums[i]): #范围的结束整数已找到
                self.addRange(startInt,endInt)
                startInt = nums[i]
            
            endInt = nums[i]    
        
        self.addRange(startInt,endInt)
        
        return self.resultRange
 
#main 函数
s = Solution()
nums = [-2,-1,0,1,2,3,4,5,6,8,10]
print(s.summaryRanges(nums))
 