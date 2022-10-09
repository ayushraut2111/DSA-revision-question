class node:
    def __init__(self,data):
        self.data=data
        self.next=None

class llist:
    def __init__(self):
        self.head=None
    
    def insertbegin(self,x):    # insertion at beginning of a list
        ptr=node(x)
        if self.head==None:
            self.head=ptr
        else:
            ptr.next=self.head
            self.head=ptr
    def insertlast(self,x):   #insertion at last of a list
        ptr=node(x)
        if self.head==None:
            self.head=ptr
        else:
            temp=self.head
            while temp.next is not None:
                temp=temp.next
            temp.next=ptr
    def insertrandom(self,loc,x):  #insert at any position in a list
        ptr=node(x)
        if self.head==None:
            self.head=ptr
            return
        if loc==1:
            ptr.next=self.head
            self.head=ptr
            return
        temp=self.head
        for i in range(loc-2):
            temp=temp.next
        ptr.next=temp.next
        temp.next=ptr


    def deletebegin(self):   # deleting at the beginning of a list
        if self.head==None:
            print("list is empty")
            return
        if self.head.next==None:
            self.head=None
            return
        self.head=self.head.next

    def deletelast(self):  # deleting at last position in a list
        if self.head==None:
            print("list is empty")
            return
        if self.head.next==None:
            self.head=None
            return
        temp=self.head
        ptr=None
        while temp.next is not None:
            ptr=temp
            temp=temp.next
        ptr.next=None

    def deleterandom(self,loc):  # deleting from random position in a list
        if self.head==None:
            print("list is empty")
            return
        if loc==1:
            self.head=self.head.next
            return
        ptr=None
        temp=self.head
        for i in range(loc-1):
            ptr=temp
            temp=temp.next
        ptr.next=temp.next

        
    def printnode(self):
        temp=self.head
        while temp is not None:
            print(temp.data)
            temp=temp.next

if __name__=="__main__":
    head=llist()
    head.insertlast(1)
    head.insertlast(2)
    head.insertlast(3)
    head.insertrandom(4,4)
    head.deleterandom(4)
    head.printnode()