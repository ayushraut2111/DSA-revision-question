class node:
    def __init__(self,data):
        self.data=data
        self.next=None

class llist:
    def __init__(self):
        self.head=None

    def insertlast(self,x):   #insertion at last of a list
        ptr=node(x)
        if self.head==None:
            self.head=ptr
        else:
            temp=self.head
            while temp.next is not None:
                temp=temp.next
            temp.next=ptr
    
    def printnode(self):   # printing of a list 
        temp=self.head
        while temp is not None:
            print(temp.data)
            temp=temp.next
    
    def sortedinsert(self,x):
        ptr=node(x)
        if x<=self.head.data:
            ptr.next=self.head
            self.head=ptr
            return
        temp=self.head
        p=None
        while x>temp.data and (temp.next is not None):
            p=temp
            temp=temp.next
        ptr.next=temp
        p.next=ptr


if __name__=="__main__":
    head=llist()
    head.insertlast(10)
    head.insertlast(20)
    head.insertlast(30)
    head.sortedinsert(22)
    head.printnode()
