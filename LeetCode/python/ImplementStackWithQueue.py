class Queue:
    def __init__(self):
        self.l = []
        
    # @param x, an integer
    # @return nothing
    def push(self, x):
        self.l.append(x)

    # @return nothing
    def pop(self):
        if(len(self.l)>0):
            self.l.remove(self.l[0])

    # @return an integer
    def peek(self):
        if(len(self.l)>0):
            return self.l[0]

    # @return an boolean
    def empty(self):
        return len(self.l) == 0
        


class Stack:
	# initialize your data structure here.
    def __init__(self):
        self.q = Queue()

    # @param x, an integer
    # @return nothing
    def push(self, x):
        helpQ = Queue()
        #先将队列顺序的元素都弹栈到辅助栈中
        while(not self.q.empty()):
            helpQ.push(self.q.peek())
            self.q.pop()
        #将压入的元素放入栈底
        self.q.push(x)
        #将压入辅助栈中的元素重新弹回到栈中
        while(not helpQ.empty()):
            self.q.push(helpQ.peek())
            helpQ.pop()        

    # @return nothing
    def pop(self):
        self.q.pop()        

    # @return an integer
    def top(self):
        return self.q.peek()        

    # @return an boolean
    def empty(self):
        return self.q.empty()	


#main函数
#测试Queue
# q = Queue()
# q.peek()
# q.pop()
# for i in range(5):
#     q.push(i)
#     
# while(not q.empty()):
#     print(q.peek())
#     q.pop()

#测试Stack
s = Stack()
for i in range(5):
    s.push(i)
    
while(not s.empty()):
    print(s.top())
    s.pop()