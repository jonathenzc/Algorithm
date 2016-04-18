from random import *

#************** BEGIN 验证是否是正态分布
def checkNorm(lst):
    rangeLst = []
    floatnum = 0

    # print(len(lst))
    cntLst = []
    for i in range(0,101):
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


tRand = Random()
qRand = Random()
sRand = Random()
rRand = Random()
coopRand = Random()
comRand = Random()
dueRand = Random()  

lst1 = []
lst2 = []
lst3 = []
lst4 = []
lst5 = []
lst6 = []
lst7 = []


avg = 3.9
stde = 0.5
for i in range(0,1000):
    ti = tRand.gauss(avg,stde)
    while(ti <= 0.5 or ti >= 5.5):
        ti = tRand.gauss(avg,stde)
    
    a = tRand.gauss(ti,0.5)
    while(a <= 0.5 or a >= 5.5):
        a = tRand.gauss(ti,0.5)
    
    a = round(a)
    a = 0.25*a-0.25
    
    lst1.append(a)
    
    
    
    for j in range(0,6):
        a = tRand.gauss(ti,1)
        while(a <= 0.5 or a >= 5.5):
            a = tRand.gauss(ti,1)

        a = round(a)
        a = 0.25*a-0.25

        if(j == 0):
            lst2.append(a)
        elif(j == 1):
            lst3.append(a)
        elif(j == 2):
            lst4.append(a)
        elif(j == 3):
            lst5.append(a)
        elif(j == 4):
            lst6.append(a)
        elif(j == 5):
            lst7.append(a)

for i in range(1000,2000):
    q = str(i+1)
    w = str(i+1000)
    str1 = str(lst1[i-1000])
    str2 = str(lst2[i-1000])
    str3 = str(lst3[i-1000])
    str4 = str(lst4[i-1000])
    str5 = str(lst5[i-1000])
    str6 = str(lst6[i-1000])
    str7 = str(lst7[i-1000])
    
    sjtu_train_owner = "insert into sjtu_train_owner(ID,ORDERID,TOTALEVALUATION,SKILL,RESPOND,COMMUNICATION,QUALITY,DUE,COOPERATION) values("+q+","+w+","+str1+","+str2+","+str3+","+str4+","+str5+","+str6+","+str7+");"
    print(sjtu_train_owner)

# totallst = []
# qLst = []
# sLst = []
# rLst = []
# coopLst = []
# comLst = []
# dueLst = []


# for i in range(0,1000):
#     ti = tRand.gauss(0.7,0.2)
#     if(ti>=1):
#         totallst.append(1)
#     else:
#         totallst.append(ti)
    
#     qi = qRand.gauss(0.65, 0.18)
#     if(qi>=1):
#         qLst.append(1)
#     else: 
#         qLst.append(qi)
    
#     si = sRand.gauss(0.73, 0.14)
#     if(si>=1):
#         sLst.append(1)
#     else:
#         sLst.append(si)
    
#     ri = rRand.gauss(0.67, 0.15)
#     if(ri>=1):
#         rLst.append(1)
#     else:
#         rLst.append(ri)
        
#     coopi = coopRand.gauss(0.82, 0.1)
#     if(coopi>=1):
#         coopLst.append(1)
#     else:
#         coopLst.append(coopi)
        
#     coomi = comRand.gauss(0.75, 0.2)
#     if(coomi >=1):
#         comLst.append(1)
#     else:
#         comLst.append(coomi)
    
#     duei = dueRand.gauss(0.66, 0.13)
#     if(duei>=1):
#         dueLst.append(1)
#     else:
#         dueLst.append(duei)   
    

            

    
#sjtu_train_buyer = "insert into sjtu_train_buyer(ID,ORDERID,PROJECTNUM) values("+q+","+w+","+e+");"
# 插入sjtu_train_owner sql
# j = str(i+1)
# w = str(i+1000)
    
# t = str(totallst[i-1000])
# q = str(qLst[i-1000])
# s = str(sLst[i-1000])
# r = str(rLst[i-1000])
# coop = str(coopLst[i-1000])
# com = str(comLst[i-1000])
# due = str(dueLst[i-1000])
    
# sjtu_train_owner = "insert into sjtu_train_owner(ID,ORDERID,TOTALEVALUATION,SKILL,RESPOND,COMMUNICATION,QUALITY,DUE,COOPERATION) values("+j+","+w+","+t+","+s+","+r+","+com+","+q+","+due+","+coop+");"

#插入sjtu_schedule
# sjtu_train_schedule_metrics = "insert into sjtu_train_buyer(ID,ORDERID,PHASERATE,CHECKPOINTRATE) values("+q+","+w+","+e+");"

# for i in range(1000,2000):
#     q = str(i+1)
#     w = str(i+1000)
#     e = str(pLst[i-1000])
#     t = str(cLst[i-1000])
    
#     sjtu_train_schedule_metrics = "insert into sjtu_train_schedule_metrics(ID,ORDERID,PHASERATE,CHECKPOINTRATE) values("+q+","+w+","+e+","+t+");"
#     print(sjtu_train_schedule_metrics)