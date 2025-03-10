#include <iostream>
#include <vector>
using namespace std;

class Graph {
    vector<vector<int>> adj_matrix;

public:
    Graph(int n)
    {
        adj_matrix = vector<vector<int>>(n, vector<int>(n, 0));
    }

    void add_edge(int u, int v)
    {
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }

    void print()
    {
        cout << "Adjacency Matrix for the Graph: " << endl;
        int n = adj_matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << adj_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n = 4;
    Graph g(n);

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 3);

    g.print();
    return 0;
}
