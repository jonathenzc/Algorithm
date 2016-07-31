class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        #先按水平中线对折交换
        n = len(matrix)
        temp = 0
        half = n//2
        for i in range(0,n,1):#每列
            for j in range(0,half,1):
                temp = matrix[j][i]
                matrix[j][i] = matrix[n-1-j][i]
                matrix[n-1-j][i] = temp
                
        #斜对角交换
        for i in range(0,n,1):
            for j in range(0,i,1):
                temp = matrix[i][j]
                matrix[i][j] = matrix[j][i]
                matrix[j][i] = temp
   
                
def buildMatrix(start,cnt):
    matrix = []
    for i in range(start,start+cnt,1):
        matrix.append(i)
    
    return matrix
    
v1 = buildMatrix(11,5)
v2 = buildMatrix(21,5) 
v3 = buildMatrix(31,5) 
v4 = buildMatrix(41,5) 
v5 = buildMatrix(51,5)

v=[]
v.append(v1)
v.append(v2)
v.append(v3)
v.append(v4)
v.append(v5)

print(v)
       
s = Solution()
s.rotate(v)

print(v)