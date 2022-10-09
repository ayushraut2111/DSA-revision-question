from pydoc import tempfilepager


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

    def deletebegin(self):   # deletion from the begining of list
        if self.head is None:
            print("list is empty")
            return
        if self.head.next is None:
            self.head=None
            return
        self.head=self.head.next
        self.head.prev=None
        return

    def deletelast(self):    # deleting last from a list
        if self.head.next is None:
            self.head=None
            return
        temp=self.head
        p=None
        while temp.next is not None:
            p=temp
            temp=temp.next
        temp.prev=None
        p.next=None

    def deleterandom(self,loc):
        if self.head.next is None:
            self.head=None
            return
        if loc==1:
            self.head=self.head.next
            self.head.prev=None
            return
        temp=self.head
        ptr=None
        for i in range(loc-1):
            ptr=temp
            temp=temp.next
        ptr.next=temp.next
        if temp.next is not None:
            temp.next.prev=ptr
        temp.next=None
        temp.prev=None

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
    head.insertrandom(4,6)
    head.deleterandom(2)
    head.printanticlockwise()