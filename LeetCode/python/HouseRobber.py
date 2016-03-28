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
            l = [0,nums[0]]
            for i in range(2,lstSize+1):
                l.append(max(l[i-2]+nums[i-1],l[i-1]))
            
            return l[lstSize]
            
        
#测试程序
s = Solution()

print(s.rob([1,2,30,4]))