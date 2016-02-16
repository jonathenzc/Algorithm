class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        high = len(nums)
        if(high == 0):
            return 0
        
        high -= 1
        low = 1
        mid = 1
        while(low < high):
            mid = (low+high)//2
            cnt = 0
            for i in nums:
                if(i <= mid):
                    cnt += 1
			
            if(cnt > mid):
                high = mid
            else:
                low = mid+1
		
		
        return low
		
s = Solution()
nums = [1,2,2,3,4,5]
print(s.findDuplicate(nums))