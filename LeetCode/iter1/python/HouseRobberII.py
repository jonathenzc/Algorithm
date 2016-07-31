class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        lstSize = len(nums)
        if(lstSize == 0):
            return 0
        elif(lstSize == 1):
            return nums[0]
        else:
            #包含第一个，去除最后一个的
            lwithFirst = [0,nums[0]]
            for i in range(2,lstSize):
                lwithFirst.append(max(lwithFirst[i-2]+nums[i-1],lwithFirst[i-1]))
            
            #包含最后一个，不包含第一个
            lwithoutFirst = [0,nums[1]]
            for i in range(2,lstSize):
                lwithoutFirst.append(max(lwithoutFirst[i-2]+nums[i],lwithoutFirst[i-1]))
                
            # print(lwithFirst)
            # print(lwithoutFirst)
            return max(lwithFirst[lstSize-1],lwithoutFirst[lstSize-1])
            
            
#测试程序
s = Solution()
print(s.rob([1,2,3,4,5]))