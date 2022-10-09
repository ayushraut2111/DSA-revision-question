class node:
    def __init__(self,data):
        self.data=data
        self.next=None

class llist:
    def __init__(self):
        self.head=None
    
    def insertbegin(self,x):
        ptr=node(x)
        if self.head==None:
            self.head=ptr
        else:
            ptr.next=self.head
            self.head=ptr
    def printnode(self):
        temp=self.head
        while temp is not None:
            print(temp.data)
            temp=temp.next

if __name__=="__main__":
    head=llist()
    head.insertbegin(1)
    head.insertbegin(2)
    head.insertbegin(3)
    head.printnode()