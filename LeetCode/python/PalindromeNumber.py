class Solution:
    # @param {integer} x
    # @return {boolean}
    def isPalindrome(self, x):
        if(x>=0 and x<10):#个位数是回文数
            return True
        
        if(x<0 or x % 10 == 0):
            return False
            
        latterHalf = 0#记录后半段的整数
        while(x>latterHalf):
            #print("x:",x," latterHalf:",latterHalf)
            digit = x%10
            #print("digit:",digit)
            x = x//10
           # print("x:",x)
            latterHalf = latterHalf*10+digit
            #print("latterHalf:",latterHalf)

        if(x == latterHalf):
            return True
                
        latterHalf //= 10
        
        if(x==latterHalf):
            return True
        else:
            return False
            
s = Solution()
if(s.isPalindrome(1)):
    print("Yes")
else:
    print("No")