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

if __name__=="__main__":
    