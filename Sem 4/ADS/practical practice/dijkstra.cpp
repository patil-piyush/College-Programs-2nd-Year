#include<iostream>
#include<vector>
#include<climits>
using namespace std;

#define V 6
#define INF INT_MAX

class dijkstra{
    private:
    vector<vector<int>> graph;
    vector<string> dnames;
    public:
    dijkstra(vector<vector<int>> input, vector<string> names){
        graph = input;
        dnames = names;
    }

    int findMinDist(vector<int> dist, vector<bool> visited){
        int minValue = INF, minindex = -1;
        for(int i=0; i<V; i++){
            if(!visited[i] && dist[i]<minValue){
                minValue = dist[i];
                minindex = i;
            }
        }
        return minindex;
    }

    void findMST(){
        vector<int> dist(V,INF);
        vector<bool> visited(V, false);
        vector<int> parent(V,-1);
        dist[0] =0;

        for(int count=0; count<V; count++){
            int u = findMinDist(dist,visited);
            visited[u] = true;

            for(int v=0; v<V; v++){
                if(graph[u][v] && !visited[v] && (dist[u]+graph[u][v] < dist[v])){
                    dist[v] = dist[u]+graph[u][v];
                    parent[v]=u;
                }
            }
        }

        cout << "Shortest Transportation Path from Source (" << dnames[0] << "):\n";
        for(int i=0; i<V; i++){
            cout<<"To "<<dnames[i]<<" - Distance - "<<dist[i]<<"\n";
        }
    }
};

int main(){
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

    dijkstra d(inputMatrix, dNames);
    d.findMST();
    return 0;
}