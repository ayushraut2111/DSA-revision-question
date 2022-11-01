class graph:
    def __init__(self,n):
        self.a=[[0 for i in range(n)] for i in range(n)]
        self.n=n
    
    def add_vertex(self,u,v,x):
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
    g1=graph(4)
    g1.add_vertex(0,1,5)
    g1.add_vertex(0,2,8)
    g1.add_vertex(1,3,15)
    g1.add_vertex(1,2,10)
    g1.add_vertex(2,3,20)
    g1.prims(0)