class Solution:
    # @param nums, an integer[]
    # @return an integer
    def Bigger(self,a,b):
        if(a>b):
            return 0
        else:
            return 1
    
    def findPeakElement(self, nums):
        listSize = len(nums)
        if(listSize == 1):
            return 0
        elif(listSize == 2):
            return self.Bigger(nums[0],nums[1])
        else:
            for i in range(1,listSize-1):
                if(nums[i-1]<nums[i] and nums[i]>nums[i+1]):
                    return i
    			
                if(i == listSize-2):
                    if(nums[i]>nums[i+1]):
                        return 0
                    else:
                        return listSize-1
					

s = Solution();
b = [3,2,1];
print(s.findPeakElement(b))