import heapq

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[] for _ in range(vertices)]

    def add_edge(self, u, v, w):
        self.graph[u].append((v,w))
        self.graph[v].append((u, w))
    
    def prim_mst(self):
        key = [float('inf')]*self.V
        parent = [-1] * self.V
        min_heap =[(0,0)]
        key[0] = 0
        in_mst = [False]*self.V

        while min_heap:
            current_distance, u = heapq.heappop(min_heap)
            in_mst[u] = True

            for v, w in self.graph[u]:
                if not in_mst[v] and w < key[v]:
                    key[v] = w
                    parent[v] = u
                    heapq.heappush(min_heap,(key[v],v))

        print("Edges in the constructed MST")
        for i in range( 1, self.V):
            print(f"{parent[i]}--{i}=={key[i]}")

if __name__ ==  "__main__":
    vertices = int(input("Enter the no. of vertices: "))

    g = Graph(vertices)

    while True:
        choice = int(input("Enter 1 to add edge else enter 0\n"))
        if choice == 1 :
            values = input("Enter values of u, v and w :").split()
            u, v, w = map(int, values)
            g.add_edge(u, v, w)
        elif choice == 0:
            break
    g.prim_mst()