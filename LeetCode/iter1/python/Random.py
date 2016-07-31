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

pLst =[]
perLst = []
for i in range(0,1000):
    ti = round(tRand.gauss(3.3,1))
    while(ti < 1 or ti > 6):
        ti = round(tRand.gauss(3.3,1))
    
    sum = 0
    sumProject = 0
    for j in range(0,ti+1):
        a = round(tRand.gauss(3,1.2))
        while(a <1 or a > 5):
            a = round(tRand.gauss(3,1.2))
        
        finishProject = a*0.75
        finishI = round(tRand.gauss(finishProject,a*0.2))
        
        while(finishI < 0 or finishI > a):
            finishI = round(tRand.gauss(finishProject,a*0.2))
        
        sum += a
        sumProject += finishI
        # print(sumProject / sum)
    
    perLst.append(sumProject/sum)
            

# print(perLst)
for i in range(0,1000):
    ti = tRand.gauss(0.78,0.12)
    if(ti >= 1):
        pLst.append(1)
    else:
        pLst.append(ti)
    
# print(pLst)
    
for i in range(1000,2000):
    q = str(i+1)
    w = str(i+1000)
    e = str(pLst[i-1000])
    t = str(perLst[i-1000])
    
    sjtu_train_schedule_metrics = "insert into sjtu_train_schedule_metrics(ID,ORDERID,PHASERATE,CHECKPOINTRATE) values("+q+","+w+","+e+","+t+");"
    print(sjtu_train_schedule_metrics)

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