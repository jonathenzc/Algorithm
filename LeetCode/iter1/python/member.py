from random import *
import math

#************** BEGIN 验证是否是正态分布
def checkNorm(lst):
    rangeLst = []
    floatnum = 0

    # print(len(lst))
    cntLst = []
    for i in range(0,):
        cntLst.append(0)

    for i in range(0,101):
        floatnum += 0.01
        rangeLst.append(floatnum)

    # print(rangeLst)

    for i in range(0,100):
        for j in lst:
            if(j>= rangeLst[i] and j< rangeLst[i+1]):
                cntLst[i] = cntLst[i] + 1
                
    for i in cntLst:
        print(i)
#************** END 验证是否是正态分布

def show(lst):
    rangelst = [0,1,2,3,4,5,6,7,8]
    cntLst = [0,0,0,0,0,0,0,0,0,0,0,0,0]
    for i in range(0,8):
        for j in lst:
            if(j>= rangelst[i] and j< rangelst[i+1]):
                cntLst[i] = cntLst[i] + 1
                
                
    for i in cntLst:
        print(i)

tRand = Random()
qRand = Random()
sRand = Random()
rRand = Random()
coopRand = Random()
comRand = Random()
dueRand = Random()  

lamda = 0.8
lst = []
for i in range(0,1500):
    r = tRand.uniform(0,lamda)
    x = round(-math.log(r/lamda)/lamda + 0.5)
    if(x>4):
        i -= 1
    else:
        lst.append(x)

# print(len(lst))

scoreLst = []
for i in lst:
    scoreLst.append(1/(math.log(i,math.e)+1))


# print(scoreLst)

for i in range(1000,2000):
    q = str(i+1)
    w = str(i+1000)
    str1 = str(scoreLst[i-1000])

    sjtu_train_buyer = "insert into sjtu_train_buyer(ID,ORDERID,PROJECTNUM) values("+q+","+w+","+str1+");"
    print(sjtu_train_buyer)