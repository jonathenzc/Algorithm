class Solution:
    # @param {integer} A
    # @param {integer} B
    # @param {integer} C
    # @param {integer} D
    # @return {integer}
    def rectangleArea(self,A,B,C,D):
        return (C-A)*(D-B)
    
    # @param {integer} A
    # @param {integer} C
    # @param {integer} E
    # @param {integer} G
    # @return {integer}
    #注释指的是宽，同样适用于长
    def intersectLength(self,A,C,E,G):
        if(C<=E or A>=G): #矩形1全部在矩形2的左边或右边
            return 0
        elif(A<=E and C<=G): #矩形1的左边在矩形2的左边，矩形1的右边在矩形2的中间
            return C-E
        elif(A<=E and C>=G): #矩形1的左边在举行2的左边，矩形1的右边在举行2的右边
            return G-E
        elif(A>=E and C<=G): #矩形1在矩形2中间 
            return C-A
        elif(A<=G and C>=G): #矩形1的左边在矩形2的中间，矩形1的右边在矩形2的右边
            return G-A
    
    # @param {integer} A
    # @param {integer} B
    # @param {integer} C
    # @param {integer} D
    # @param {integer} E
    # @param {integer} F
    # @param {integer} G
    # @param {integer} H
    # @return {integer}
    def computeArea(self, A, B, C, D, E, F, G, H):
        rect1 = self.rectangleArea(A,B,C,D)
        rect2 = self.rectangleArea(E,F,G,H)

        #返回相交正方形的宽
        width = self.intersectLength(A,C,E,G)

        #返回相交正方形的长
        height = self.intersectLength(F,H,B,D)

        return rect1+rect2-width*height
        
#测试函数
s = Solution()
print(s.computeArea(-2,-2,2,2,-1,-1,1,1))