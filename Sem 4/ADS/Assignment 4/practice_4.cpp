#include<iostream>
#include<vector>
#include <climits>
using namespace std;

#define V 5
#define INF INT_MAX

class PrimMst{
    private:
    int graph[V][V];
    vector<string> DepartmentNames;

    public:
    PrimMst(int inputGraph[V][V], vector<string> names){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                graph[i][j] = inputGraph[i][j];
            }
        }
        DepartmentNames = names;
    }

    int findMinKey(vector<int> &key, vector<bool> &inMST){
        int minValue = INF, minIndex = -1;
        for(int i=0; i<V; i++){
            if(!inMST[i] && key[i]<minValue){
                minValue = key[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    void findMST(){
        vector<int> parent(V, -1);
        vector<int> key(V, INF);
        vector<bool> inMST(V, false);

        key[0]=0;
        
        for(int count = 0; count<V; count++){
            
            int u = findMinKey(key, inMST);
            inMST[u] = true;
            

            for(int v=0; v<V; v++){
                if(graph[u][v] != 0 && !inMST[v] && graph[u][v]<key[v]){
                    key[v] = graph[u][v];
                    parent[v] = u;
                }
            }
        }



        //printing the mst
        int total =0;
        for(int i=1; i<V; i++){
            cout << DepartmentNames[parent[i]] << " - " << DepartmentNames[i]
                 << "  Distance: " << graph[parent[i]][i] << " meters\n";
            total += graph[parent[i]][i];
        }
        cout<<"total distance - "<<total;


    }
};

int main(){
    int inputGraph[V][V] = {
        {0, 70, 90, 0, 0},   // ENTC
        {30, 0, 35, 40, 0},  // AIML
        {70, 50, 0, 47, 85}, // CS
        {0, 89, 55, 0, 23},  // IT
        {0, 0, 67, 34, 0}    // MECH
    };

    vector<string> names = {"ENTC", "AIML","CS", "IT", "MECH"};

    PrimMst g(inputGraph, names);
    g.findMST();

    return 0;
}