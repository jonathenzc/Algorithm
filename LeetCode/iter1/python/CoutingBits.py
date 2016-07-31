class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        bitLst = []
        if(num>=0):
            bitLst.append(0)
            for i in range(1,num+1):
                bitLst.append(bitLst[i>>1]+(i&1));
        
        return bitLst
        
        
#测试程序
s = Solution()
print(s.countBits(5))