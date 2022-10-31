class graph:
    def __init__(self,n):
        self.a=[[0 for i in range(n)] for i in range(n)]
        self.n=n
    def prnt(self):
        for i in self.a:
            for j in i:
                print(j,end=" ")
            print()
    def add_vertex(self,u,v):
        self.a[u][v]=1
        self.a[v][u]=1

    def bfs(self,i):
        visited=[False for i in range(self.n)]
        q=[]
        q.append(i)
        visited[i]=True
        while q:
            r=q.pop(0)
            print(r,end=" ")
            for i in range(self.n):
                if self.a[r][i]==1 and visited[i]==False:
                    q.append(i)
                    visited[i]=True
        


if __name__=="__main__":
    g1=graph(4)
    g1.add_vertex(0,1)
    g1.add_vertex(0,2)
    g1.add_vertex(1,3)
    g1.bfs(0)