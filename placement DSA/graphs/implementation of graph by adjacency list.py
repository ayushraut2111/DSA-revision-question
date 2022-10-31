class graph:
    def __init__(self,n):
        self.a=[[] for i in range(n)]

    def add_vertex(self,u,v):
        self.a[u].append(v)
        self.a[v].append(u)

    def prnt(self):
        print(self.a)

if __name__=="__main__":
    g1=graph(4)
    g1.add_vertex(0,1)
    g1.add_vertex(2,3)
    g1.prnt()