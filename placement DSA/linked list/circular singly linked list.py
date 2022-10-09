from unicodedata import name


class node:
    def __init__(self,x):
        self.data=x
        self.next=None

class llist:
    def __init__(self):
        self.head=None

    def insertbegin(self,x):
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

    def printlist(self):
        temp=self.head
        while temp.next is not self.head:
            print(temp.data)
            temp=temp.next
        print(temp.data)

if __name__=="__main__":
    head=llist()
    head.insertbegin(1)
    head.insertbegin(2)
    head.insertbegin(3)
    head.printlist()
