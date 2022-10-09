class node:
    def __init__(self,x):
        self.data=x
        self.next=None
        self.prev=None
class llist:
    def __init__(self):
        self.head=None

    def insertbegin(self,x):  #insertion at beginning of a list
        ptr=node(x)
        if self.head==None:
            self.head=ptr
            return
        ptr.next=self.head
        self.head.prev=ptr
        self.head=ptr
        return
    
    def printclockwise(self):
        temp=self.head
        while temp is not None:
            print(temp.data)
            temp=temp.next
    
    def printanticlockwise(self):
        temp=self.head
        while temp.next is not None:
            temp=temp.next
        while temp is not None:
            print(temp.data)
            temp=temp.prev

if __name__=="__main__":
    head=llist()
    head.insertbegin(1)
    head.insertbegin(2)
    head.insertbegin(3)
    head.printclockwise()