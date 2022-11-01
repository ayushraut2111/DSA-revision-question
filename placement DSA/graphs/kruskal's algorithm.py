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

    def check_cycle(self,visited,i):
        q=[]
        q.append(i)
        evisited=[False for i in range(self.n)]
        count=0
        while q:
            r=q.pop(0)
            if i==r and count!=0:
                return True
            for j in range(self.n):
                if visited[j]==True and self.a[r][j]!=0 and evisited[j]==False:
                    q.append(j)
                    evisited[j]=True
            count+=1
        return False

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
        print(array)
        for i in array:
            if not self.check_cycle(visited,i[1]):   
                prm.append(i)
                visited[i[1]]=True
                visited[i[2]]=True
                ans+=i[0]
        for i in prm:
            print(str(i[1])+"-"+str(i[2])+" "+str(i[0]))
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
    g1.kruskal()
