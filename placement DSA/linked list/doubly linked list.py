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
        
    def insertlast(self,x):  #insertion at last of a list
        ptr=node(x)
        if self.head==None:
            self.head=ptr
            return
        temp=self.head
        while temp.next is not None:
            temp=temp.next
        temp.next=ptr
        ptr.prev=temp
    
    def insertrandom(self,loc,x):    # insertion at random position
        ptr=node(x)
        if self.head==None:
            self.head=ptr
            return
        if loc==1:
            ptr.next=self.head
            self.head.prev=ptr
            self.head=ptr
            return
        temp=self.head
        for i in range(loc-2):
            temp=temp.next
        ptr.next=temp.next
        if temp.next is not None:
            temp.next.prev=ptr
        temp.next=ptr
        ptr.prev=temp
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
    head.insertlast(1)
    head.insertlast(2)
    head.insertlast(3)
    head.insertrandom(3,6)
    head.printanticlockwise()