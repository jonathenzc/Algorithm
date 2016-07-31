class Solution:
    # @param {integer} num
    # @return {string}
    def intToRoman(self, num):
        romanNum = [1000,900,500,400,100,90,50,40,10,9,5,4,1]
        romanLetter = ["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"]
        result = ""
        for (n,l) in zip(romanNum,romanLetter):
            while(num>=n):
                result += l
                num -= n
                
        return result
        
#测试程序
s = Solution()
print(s.intToRoman(10))
print(s.intToRoman(4))
print(s.intToRoman(7))
print(s.intToRoman(9))
print(s.intToRoman(3999))