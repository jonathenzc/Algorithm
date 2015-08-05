class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def singleNumber(self, nums):
        #利用异或来求：如果两个数相同，那么会变成0；那么题目中的所有相同的数对就会变成0，最终剩下的就是那个单数
        result = 0
        for num in nums:
            result ^= num
		
        return result
		
		
#测试程序
a = [1,1,2,2,3,8,8]
s = Solution()
print(s.singleNumber(a))