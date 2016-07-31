class Stack:
    def __init__(self):
        self.l = []
        
    # @param x, an integer
    # @return nothing
    def push(self, x):
        self.l.insert(0,x)

    # @return nothing
    def pop(self):
        if(len(self.l)>0):
            self.l.remove(self.l[0])

    # @return an integer
    def top(self):
        if(len(self.l)>0):
            return self.l[0]

    # @return an boolean
    def empty(self):
        return len(self.l) == 0
        


class Queue:
    # initialize your data structure here.
    def __init__(self):
        self.s = Stack()
        
    # @param x, an integer
    # @return nothing
    def push(self, x):
        helpS = Stack()
        #先将队列顺序的元素都弹栈到辅助栈中
        while(not self.s.empty()):
            helpS.push(self.s.top())
            self.s.pop()
        #将压入的元素放入栈底
        self.s.push(x)
        #将压入辅助栈中的元素重新弹回到栈中
        while(not helpS.empty()):
            self.s.push(helpS.top())
            helpS.pop()

    # @return nothing
    def pop(self):
        self.s.pop()

    # @return an integer
    def peek(self):
        return self.s.top()
    # @return an boolean
    def empty(self):
        return self.s.empty()


#main函数
#测试Stack
# s = Stack()
# s.top()
# s.pop()
# for i in range(5):
#     s.push(i)
#     
# while(not s.empty()):
#     print(s.top())
#     s.pop()

#测试Queue
q = Queue()
for i in range(5):
    q.push(i)
    
while(not q.empty()):
    print(q.peek())
    q.pop()