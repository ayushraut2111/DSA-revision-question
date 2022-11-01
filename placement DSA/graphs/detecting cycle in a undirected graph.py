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

    def cycle(self,visited,i,parent):
        visited[i]=True
        for j in range(self.n):
            if visited[j]==False and self.a[i][j]!=0:
                if self.cycle(visited,j,i)==True:
                    return True
            elif j!=parent and self.a[i][j]!=0:
                return True
        return False
                

    def cycle_main(self):
        visited=[False for i in range(self.n)]
        for i in range(self.n):
            if visited[i]==False:
                if self.cycle(visited,i,-1)==True:
                    return True
        return False

if __name__=="__main__":
    g1=graph(6)
    g1.add_vertex(0,1)
    g1.add_vertex(1,3)
    g1.add_vertex(1,2)
    g1.add_vertex(2,3)
    g1.add_vertex(2,4)
    g1.add_vertex(4,5)
    if g1.cycle_main():
        print("cycle found")
    else:
        print("cycle not found")
    