#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define V 5
#define INF INT_MAX

class prim
{
private:
    int graph[V][V];
    vector<string> dnames;

public:
    prim(int input[V][V], vector<string> names)
    {
        dnames = names;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                graph[i][j] = input[i][j];
            }
        }
    }

    int findMinDistance(vector<int> &key, vector<bool> inMST)
    {
        int minValue = INF, minIndex = -1;
        for (int i = 0; i < V; i++)
        {
            if (!inMST[i] && key[i] < minValue)
            {
                minValue = key[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    void findPath()
    {
        vector<bool> inMST(V, false);
        vector<int> key(V, INF);
        vector<int> parent(V, -1);
        key[0] = 0;

        for (int count = 0; count < V; count++)
        {
            int u = findMinDistance(key, inMST);
            inMST[u] = true;

            for (int v = 0; v < V; v++)
            {
                if (!inMST[v] && graph[u][v] && graph[u][v] < key[v])
                {
                    key[v] = graph[u][v];
                    parent[v] = u;
                }
            }

            // Print MST with department names
            cout << "Minimum Spanning Tree (MST) of College Campus:\n";
            int totalDistance = 0;
            for (int i = 1; i < V; i++)
            {
                cout << dnames[parent[i]] << " - " << dnames[i]
                     << "  Distance: " << graph[parent[i]][i] << " meters\n";
                totalDistance += graph[parent[i]][i];
            }
            cout << "Total Minimum Distance to Connect All Departments: " << totalDistance << " meters\n";
        }
    }
};

    int main()
    {
        // Given adjacency matrix (distances between departments)
        int inputGraph[V][V] = {
            {0, 70, 90, 0, 0},   // ENTC
            {30, 0, 35, 40, 0},  // AIML
            {70, 50, 0, 47, 85}, // CS
            {0, 89, 55, 0, 23},  // IT
            {0, 0, 67, 34, 0}    // MECH
        };

        // Department names corresponding to indices
        vector<string> departmentNames = {"ENTC", "AIML", "CS", "IT", "MECH"};

        prim campus(inputGraph, departmentNames);
        campus.findPath();

        return 0;
    }
