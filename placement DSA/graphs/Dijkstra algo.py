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

    def dijkstra(self,source,visited,dist):     
        visited[source]=True
        for i in range(self.n):
            if self.a[source][i]!=0 and (visited[i]==False or (dist[source]+self.a[source][i]<dist[i])):
                dist[i]=min(dist[i],dist[source]+self.a[source][i])
                self.dijkstra(i,visited,dist)

    
    def start_point_dijkstra(self,source):
        visited=[False for i in range(self.n)]
        dist=[9999999 for i in range(self.n)]
        dist[source]=0
        self.dijkstra(source,visited,dist)
        print(dist)
        

if __name__=="__main__":
    g1=graph(4)
    g1.add_vertex(0,1,50)
    g1.add_vertex(0,2,100)
    g1.add_vertex(1,2,30)
    g1.add_vertex(1,3,200)
    g1.add_vertex(2,3,20)
    g1.start_point_dijkstra(0)