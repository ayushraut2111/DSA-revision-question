class node:
    def __init__(self,x):
        self.data=x
        self.next=None
        self.prev=None

class llist:
    def __init__(self):
        self.head=None
    
    def insertbegin(self,x):    # insertion at beginning
        ptr=node(x)
        if self.head is None:
            self.head=ptr
            self.head.next=self.head
            self.head.prev=self.head
            return
        temp=self.head.prev
        ptr.next=self.head
        self.head.prev=ptr
        self.head=ptr
        self.head.prev=temp
        temp.next=self.head
    
    def insertlast(self,x):   # inserting at last of a node
        ptr=node(x)
        if self.head is None:
            self.head=ptr
            self.head.next=self.head
            self.head.prev=self.head
            return
        temp=self.head.prev
        temp.next=ptr
        ptr.prev=temp
        ptr.next=self.head
        self.head.prev=ptr
    
    def insertrandom(self,loc,x):   # insertion at random position
        ptr=node(x)
        if self.head is None:
            self.head=ptr
            self.head.next=self.head
            self.head.prev=self.head
            return
        if loc==1:
            temp=self.head.prev
            ptr.next=self.head
            self.head.prev=ptr
            self.head=ptr
            self.head.prev=temp
            temp.next=self.head
            return
        temp=self.head
        for i in range(loc-2):
            temp=temp.next
        ptr.next=temp.next
        ptr.prev=temp
        temp.next.prev=ptr
        temp.next=ptr

    def deletebegin(self):      # deleting at the beginning of the list
        if self.head.next is self.head:
            self.head=None
            return
        temp=self.head.prev
        self.head=self.head.next
        self.head.prev=temp
        temp.next=self.head
    
    def deletelast(self):    # deleting from last of a list
        if self.head.next is self.head:
            self.head=None
            return
        temp=self.head.prev.prev
        temp.next=self.head
        self.head.prev=temp

    def deleterandom(self,loc):    # deleting at random position
        if self.head.next is self.head:
            self.head=None
            return
        if loc==1:
            temp=self.head.prev
            self.head=self.head.next
            self.head.prev=temp
            temp.next=self.head
            return
        temp=self.head
        ptr=None
        for i in range(loc-1):
            ptr=temp
            temp=temp.next
        ptr.next=temp.next
        temp.next.prev=ptr
    
    def searchlist(self,x):   # searching in a linked list
        if self.head.data is x:
            print("found")
            return
        temp=self.head.next
        while temp is not self.head:
            if temp.data is x:
                print("found")
                return
            temp=temp.next
        print("not found")
        

    def printclockwise(self):     # printing clockwise of a list
        temp=self.head
        while temp.next is not self.head:
            print(temp.data)
            temp=temp.next
        print(temp.data)

    def printanticlockwise(self):    # printing anticlockwise in a list
        temp=self.head.prev
        while temp is not self.head:
            print(temp.data)
            temp=temp.prev
        print(temp.data)

if __name__=="__main__":
    head=llist()
    head.insertlast(1)
    head.insertlast(2)
    head.insertlast(3)
    head.insertrandom(4,4)
    head.searchlist(2)
    head.printclockwise()

