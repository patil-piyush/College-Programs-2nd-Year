#include <iostream>
#include <climits>
#include <vector>
using namespace std;

#define INF INT_MAX
#define V 6

class dijkstraSCM{
    private:
    vector<vector<int>> graph;
    vector<string> dnames;

    public:
    dijkstraSCM(vector<vector<int>> inputgraph, vector<string> names){
        graph = inputgraph;
        dnames = names;
    }

    int findMinDist(vector<int> dist, vector<bool> visited){
        int minValue = INF, minIndex = -1;
        for(int i=0; i<V; i++){
            if(!visited[i] && dist[i]<minValue){
                minValue = dist[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    void findPath(int src){
        vector<int> dist(V, INF);
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        dist[src] = 0;

        for(int count = 0; count<V; count++){
            int u = findMinDist(dist, visited);
            visited[u]=true;

            for(int v=0; v<V; v++){
                if(!visited[v] && graph[u][v] && dist[u] != INF && (dist[v] > dist[u] + graph[u][v]) ){
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }

        cout << "Shortest Transportation Path from Source (" << dnames[src] << "):\n";
        for(int i=0; i<V; i++){
            cout<<"To "<<dnames[i]<<" - Distance - "<<dist[i]<<" | Path - ";
            int temp = i;
            vector<string> path;
            while(temp>0){
                path.push_back(dnames[temp]);
                temp = parent[temp];
            }
            for(int j= path.size()-1; j>=0; j--){
                cout<<path[j]<< (j>0? " -> ": "\n");
            }   
        }

    }

};

int main()
{
    vector<vector<int>> inputMatrix = {
        {0, 163, 0, 40, 150, 0},  // Supplier
        {10, 0, 50, 0, 0, 120},   // Warehouse
        {0, 55, 0, 40, 15, 0},    // Distribution Center 1
        {10, 0, 25, 0, 65, 0},    // Distribution Center 2
        {105, 0, 104, 67, 0, 51}, // Retail Store 1
        {0, 20, 0, 0, 50, 0}      // Retail Store 2
    };

    vector<string> dNames = {
        "Supplier", "Warehouse", "Distribution Center 1",
        "Distribution Center 2", "Retail Store 1", "Retail Store 2"};

    dijkstraSCM d(inputMatrix, dNames);
    d.findPath(0);
    return 0;
}