class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def singleNumber(self, nums):
        numDict = {}
        for num in nums:
            if num in numDict:
                numDict[num] += 1
            else:
                numDict[num] = 1
        
        for key in numDict: #遍历的是key
            if(numDict[key] == 1):
                return key
                
                
#测试程序
s = Solution()
l = [1,1,1,2,2,2,3,3,3,4]
print(s.singleNumber(l))