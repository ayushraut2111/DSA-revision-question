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
    def prims(self,source):     # prims algo 
        q=[source]
        prm=[]
        visited=[False for i in range(self.n)]
        visited[source]=True
        ans=0
        while len(q)!=self.n:
            mini=999999
            temp=999999
            for i in range(self.n):
                if visited[i]==True:
                    for j in range(self.n):
                        if self.a[i][j]!=0 and visited[j]==False and self.a[i][j]<mini:
                            mini=min(self.a[i][j],mini)
                            temp=j
                            prm.append((i,j,self.a[i][j]))
            q.append(temp)
            visited[temp]=True
            ans+=mini
        for i in prm:
            print(str(i[0])+"-"+str(i[1])+" "+str(i[2]))
        print("minimum spanning tree cost is "+ str(ans))

if __name__=="__main__":
    g1=graph(9)
    g1.add_vertex(7,6,1)
    g1.add_vertex(8,2,2)
    g1.add_vertex(6,5,2)
    g1.add_vertex(0,1,4)
    g1.add_vertex(2,5,4)
    g1.add_vertex(8,6,6)
    g1.add_vertex(2,3,7)
    g1.add_vertex(7,8,7)
    g1.add_vertex(0,7,8)
    g1.add_vertex(1,2,8)
    g1.add_vertex(3,4,9)
    g1.add_vertex(5,4,10)
    g1.add_vertex(1,7,11)
    g1.add_vertex(3,5,14)
    g1.prims(0)