class Solution:
    # @param {integer[]} nums
    # @return {boolean}
    def containsDuplicate(self, nums):	
        wordDict = {}
        for n in nums:
            if n in wordDict:
                return True
            wordDict[n] = 0
			
        return False	
        	
#测试函数
s = Solution()
a = [1,2,3,4,56,1]
print(s.containsDuplicate(a))