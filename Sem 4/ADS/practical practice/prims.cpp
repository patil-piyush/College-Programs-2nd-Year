#include<iostream>
#include<vector>
#include<climits>
using namespace std;

#define V 5
#define INF INT_MAX

class prim{
    private:
    vector<vector<int>> graph;
    vector<string> dnames;
    public:
    prim(vector<vector<int>> input, vector<string> names){
        graph = input;
        dnames = names;
    }

    int findMinKey(vector<int> key, vector<bool> inMST){
        int minValue = INF, minindex= -1;
        for(int i=0; i<V; i++){
            if(!inMST[i] && key[i]<minValue){
                minValue = key[i];
                minindex = i;
            }
        }
        return minindex;
    }

    void findMST(){
        vector<int> key(V, INF);
        vector<bool> inMST(V, false);
        vector<int> parent(V,-1);
        key[0] = 0;

        for(int count =0; count<V; count++){
            int u = findMinKey(key,inMST);
            inMST[u] = true;
            
            for(int v=0; v<V; v++){
                if(!inMST[v] && graph[u][v] && graph[u][v]<key[v]){
                    key[v] = graph[u][v];
                    parent[v] = u;
                }
            }
        
        }

        int total=0;
        for(int i=1; i<V; i++){
            cout<<dnames[parent[i]]<<" - "<<dnames[i]<<"\t"<<graph[parent[i]][i]<<endl;
        }

    }
};

int main(){
    vector<vector<int>> inputGraph = {
        {0, 70, 90, 0, 0},   // ENTC
        {30, 0, 35, 40, 0},  // AIML
        {70, 50, 0, 47, 85}, // CS
        {0, 89, 55, 0, 23},  // IT
        {0, 0, 67, 34, 0}    // MECH
    };

    // Department names corresponding to indices
    vector<string> departmentNames = {"ENTC", "AIML", "CS", "IT", "MECH"};

    prim campus(inputGraph, departmentNames);
    campus.findMST();

    return 0;
}