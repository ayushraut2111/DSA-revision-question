class graph:
    def __init__(self,n):
        self.a=[[0 for i in range(n)] for i in range(n)]
        self.n=n
    
    def add_vertex(self,u,v):
        self.a[u][v]=1
        self.a[v][u]=1
    
    def prnt(self):
        for i in self.a:
            for j in i:
                print(j,end=" ")
            print()

    def shortest_path(self,x):
        visited=[False for i in range(self.n)]
        dist=[0 for i in range(self.n)]
        dist[x]=0
        visited[x]=True
        q=[]
        q.append(x)
        while q:
            r=q.pop(0)
            for i in range(self.n):
                if self.a[r][i]==1 and visited[i]==False:
                    dist[i]=dist[r]+1
                    visited[i]=True
                    q.append(i)
        print(dist)


if __name__=="__main__":
    g1=graph(6)
    g1.add_vertex(0,2)
    g1.add_vertex(0,1)
    g1.add_vertex(0,4)
    g1.add_vertex(1,3)
    g1.add_vertex(3,2)
    g1.add_vertex(3,5)
    g1.add_vertex(5,4)
    g1.add_vertex(4,2)
    g1.shortest_path(0)