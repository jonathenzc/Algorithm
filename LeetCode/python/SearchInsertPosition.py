class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer}
    def searchInsert(self, nums, target):
        listSize = len(nums)
		
        if(listSize == 0):
            return 0
		
        if(target<nums[0]):
            return 0
		
        if(target > nums[listSize-1]):
            return listSize
		
        start = 0
        end = listSize
        mid = 0
        isFound = False
        while(start<end):
            mid = (start+end)//2
            # print("start ",start," end ",end," mid ",mid)
            if(nums[mid] == target):
                isFound = True
                break
			
            if(target<nums[mid]):
                end = mid
            else:
                start = mid+1
		
        if(not isFound and mid<listSize and end<listSize and
            nums[mid]<nums[end]):
            return mid+1
		
        return mid
		
#测试程序				
s = Solution()
l = [x for x in range(0,9,2)]

print(l)

for i in range(-2,12,1):
    print(i,s.searchInsert(l,i))