class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @return {boolean}
    def containsNearbyDuplicate(self, nums, k):
        wordDict = {}
        numSize = len(nums)
        for i in range(numSize):
            if nums[i] in wordDict:
                if(i-wordDict[nums[i]] <= k):
                    return True
            wordDict[nums[i]] = i
		
        return False
		
#测试函数
s = Solution()
a = [1,2,3,1,4,1,5,6]
print(s.containsNearbyDuplicate([],0))