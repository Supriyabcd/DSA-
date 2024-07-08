#include<bits/stdc++.h>
using namespace std;

class Graph_adj_matrix{
    public:
        void addEdge(int u, int v){
            graph[u].push_back(v);
        }

        void removeEdge(int u, int v){
            auto it = find(graph[u].begin(), graph[u].end(), v);
            if(it != graph[u].end()){
                graph[u].erase(it);
            }
        }

        vector<int> getNeighbours(int u){
            if (graph.find(u) != graph.end()){
                return graph[u];
            }
            return {};
        }

        void printGraph(){
            for (const auto& pair : graph){
                cout << pair.first << " : ";
                for (int v : pair.second){
                    cout << v << " ";
                }
                cout << endl;
            }
        }

    private:
        unordered_map<int,vector<int>>graph;

};
   
int main()
{
    Graph_adj_matrix g;
    int u, v, choice;
    while (true){
        cout << "\n Graph Menu:" << endl;
        cout << "1. Add Edge" << endl;
        cout << "2. Remove Edge" << endl;
        cout << "3. Get neighbours" << endl;
        cout << "4. Print graph" << endl;
        cout << "0. Exit " << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1: cout << "Enter values of u & v : " ;
                cin >> u >> v;
                g.addEdge(u,v);            
            break;
        case 2: cout << "Enter values of u & v : " ;
                cin >> u >> v;
                g.removeEdge(u,v);
            break;
        case 3: cout << "Enter the vertex:" ;
                cin >> u;
                cout << "Neighbours of "<< u << " : ";
                for( int neighbour : g.getNeighbours(1)){
                     cout << neighbour << " ";
                }
                cout << endl;
            break;
        case 4: cout << "Graph:\n";
                g.printGraph();
            break;
        case 0: cout << "Exiting...";
                exit(0);
            break;
        default: cout << "Invalid choice. Please try again";
            break;
        }
    }
    return 0;
}