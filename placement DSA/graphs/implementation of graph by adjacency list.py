class graph:
    def __init__(self,n):
        self.a=[[] for i in range(n)]

    def add_vertex(self,u,v):
        self.a[u].append(v)
        self.a[v].append(u)

    def prnt(self):
        for i in self.a:
            for x in i:
                print(x,end=" ")
            print()
    
    def bfs_connected(self,s):                        # this bfs is applied when the graph is connected
        visited=[False for i in range(len(self.a))]
        q=[]
        visited[s]=True
        q.append(s)
        while q:
            r=q.pop(0)
            print(r, end=" ")
            for i in self.a[r]:
                if visited[i]==False:
                    q.append(i)
                    visited[i]=True

    def bfs(self,i,visited):    # this is a bfs for connected graph
        q=[]
        q.append(i)
        visited[i]=True
        while q:
            r=q.pop(0)
            print(r,end=" ")
            for i in self.a[r]:
                if visited[i]==False:
                    q.append(i)
                    visited[i]=True

    def bfs_dis(self):     # this is a function which is used to pass the disconnected node of a graph
        visited=[False for i in range(len(self.a))]
        for i in range(len(self.a)):
            if visited[i]== False:
                self.bfs(i,visited)


if __name__=="__main__":
    g1=graph(4)
    g1.add_vertex(0,1)
    g1.add_vertex(0,2)
    g1.add_vertex(1,2)
    g1.add_vertex(1,3)
    g1.bfs_dis()