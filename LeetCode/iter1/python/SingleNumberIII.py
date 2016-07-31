class Solution:
    # @param {integer[]} nums
    # @return {integer[]}
    def singleNumber(self, nums):
        numDict = {}
		#记录数字和出现次数的映射
        for num in nums:
            if num in numDict:
                numDict[num] += 1
            else:
                numDict[num] = 1
				
        result = []		
		#遍历这个字典
        for key in numDict:
            if numDict[key] == 1:
                result.append(key)
				
        return result

#测试程序
s = Solution()
nums = [1,3,1,3,2,5]
print(s.singleNumber(nums))