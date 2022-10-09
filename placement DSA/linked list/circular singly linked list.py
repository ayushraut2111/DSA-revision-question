class node:
    def __init__(self,x):
        self.data=x
        self.next=None

class llist:
    def __init__(self):
        self.head=None

    def insertbegin(self,x):    # insertion at the beginning
        ptr=node(x)
        if self.head is None:
            self.head=ptr
            self.head.next=self.head
            return
        temp=self.head
        while temp.next is not self.head:
            temp=temp.next
        ptr.next=self.head
        self.head=ptr
        temp.next=self.head

    def insertlast(self,x):   # insertion at last
        ptr=node(x)
        if self.head is None:
            self.head=ptr
            self.head.next=self.head
            return
        temp=self.head
        while temp.next is not self.head:
            temp=temp.next
        temp.next=ptr
        ptr.next=self.head

    def insertrandom(self,loc,x):   # inserting at random position
        ptr=node(x)
        if self.head is None:
            self.head=ptr
            self.head.next=self.head
            return
        if loc==1:
            temp=self.head
            while temp.next is not self.head:
                temp=temp.next
            ptr.next=self.head
            self.head=ptr
            temp.next=self.head
            return
        temp=self.head
        for i in range(loc-2):
            temp=temp.next
        if temp.next is self.head:
            temp.next=ptr
            ptr.next=self.head
            return
        ptr.next=temp.next
        temp.next=ptr
    
    def deletebegin(self):   # deletion from beginning
        if self.head.next is self.head:
            self.head=None
            return
        temp=self.head
        while temp.next is not self.head:
            temp=temp.next
        self.head=self.head.next
        temp.next=self.head

    def deletelast(self):     # deletion from last 
        if self.head.next is self.head:
            self.head=None
            return
        temp=self.head
        ptr=None
        while temp.next is not self.head:
            ptr=temp
            temp=temp.next
        ptr.next=self.head

    def deleterandom(self,loc):    # deleting random from a list
        if self.head.next is self.head:
            self.head=None
            return
        if loc==1:
            temp=self.head
            while temp.next is not self.head:
                temp=temp.next
            self.head=self.head.next
            temp.next=self.head
            return
        temp=self.head
        ptr=None
        for i in range(loc-1):
            ptr=temp
            temp=temp.next
        ptr.next=temp.next

    def searchlist(self,x):    # searching in a linked list
        if self.head is x:
            print("found at location 1")
            return
        i=2
        temp=self.head.next
        while temp is not self.head:
            if temp.data is x:
                print("found at loc "+ str(i))
                return
            temp=temp.next
            i+=1
        print("not found")

        

    def printlist(self):
        temp=self.head
        while temp.next is not self.head:
            print(temp.data)
            temp=temp.next
        print(temp.data)

if __name__=="__main__":
    head=llist()
    head.insertlast(1)
    head.insertlast(2)
    head.insertlast(3)
    head.insertrandom(4,4)
    head.searchlist(4)
    head.printlist()
