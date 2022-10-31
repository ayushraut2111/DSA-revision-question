class graph:
    def __init__(self,n):
        self.a=[[] for i in range(n)]

    def insert(self,u,v):
        self.a[u].append(v)
        self.a[v].append(u)

    def prnt(self):
        print(self.a)