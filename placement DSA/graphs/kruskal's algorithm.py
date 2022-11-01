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
    def kruskal(self):
        visited=[False for i in range(self.n)]
        prm=[]   # in this array our minimum spanning tree will be saved
        array=[]
        ans=0
        for i in range(self.n):
            for j in range(i+1,self.n):   # this step is used to take only the half of matrix as it is directed graph so vertexs will repeat if we dont take half then also there will be no problem only time complexity increases
                if self.a[i][j]!=0: 
                    array.append((self.a[i][j],i,j))   # in array we will save all the costs and vertex in minimum order for this we sort it
        array.sort()
        # print(array)
        for i in array:
            if not visited[i[1]] or not visited[i[2]]:   # if any one of the index is not visited that means there will be no cycle formed when we connect those edges
                prm.append(i)
                visited[i[1]]=True
                visited[i[2]]=True
                ans+=i[0]
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
    g1.kruskal()
