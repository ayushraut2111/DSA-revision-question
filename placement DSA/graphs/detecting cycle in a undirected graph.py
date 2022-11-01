class graph:
    def __init__(self,n):
        self.a=[[0 for i in range(n)] for i in range(n)]
        self.n=n
    
    def add_vertex(self,u,v,x=1):
        self.a[u][v]=x
        self.a[v][u]=x
    
    def prnt(self):
        for i in self.a:
            for j in i:
                print(j,end=" ")
            print()

if __name__=="__main__":
    g1=graph(6)
    g1.add_vertex(0,1)
    g1.add_vertex(1,3)
    g1.add_vertex(1,2)
    g1.add_vertex(2,3)
    g1.add_vertex(2,4)
    g1.add_vertex(4,5)
    g1.prnt()
    