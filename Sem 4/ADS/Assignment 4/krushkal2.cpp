#include <iostream> // for cout, etc.
#include <climits>  // for INT_MAX (biggest int value)
using namespace std;

#define I INT_MAX  // 'I' stands for infinity here
#define V 7        // total number of vertices (departments/nodes)

class krushkal
{
public:
    int set[8];      // Disjoint Set Array (to track parent sets for union-find)
    int edges[3][9]; // Edge list: [0]=u, [1]=v, [2]=weight
    int included[9]; // Marks if an edge is already considered (1) or not (0)
    int t[2][6];     // To store result MST: [0]=u, [1]=v
    int weight[6];   // To store weights of selected MST edges

    krushkal(int matrix[V][V])
    {
        // Properly initialize all elements
        for (int i = 0; i < 8; i++)
            set[i] = -1;
        for (int i = 0; i < 9; i++)
        {
            included[i] = 0;
            edges[0][i] = edges[1][i] = edges[2][i] = 0;
        }

        // for converting the matrix to edges array
        int k = 0;
        for (int i = 0; i < V; i++)
        {
            for (int j = i + 1; j < V; j++)
            {
                if (matrix[i][j] != 0)
                {
                    edges[0][k] = i + 1;
                    edges[1][k] = j + 1;
                    edges[2][k] = matrix[i][j];
                    k++;
                }
            }
        }
    }

    // for performing union of two vertices
    void myUnion(int u, int v)
    {
        if (set[u] < set[v])
        {
            set[u] = set[u] + set[v];
            set[v] = u;
        }
        else
        {
            set[v] = set[u] + set[v];
            set[u] = v;
        }
    }

    // for finding the parent
    int find(int u)
    {
        int x = u, v = 0;
        while (set[x] > 0)
        {
            x = set[x];
        }
        while (u != x)
        {
            v = set[u];
            set[u] = x;
            u = v;
        }
        return x;
    }

    void findMST()
    {
        int i = 0, j, min, k, v, u, e = 9;

        while (i < V - 1)
        {
            min = I;
            for (j = 0; j < e; j++)
            {
                if (included[j] == 0 && edges[2][j] < min)
                {
                    u = edges[0][j];
                    v = edges[1][j];
                    min = edges[2][j];
                    k = j;
                }
            }

            if (find(u) != find(v))
            {
                t[0][i] = u;
                t[1][i] = v;
                myUnion(find(u), find(v));
                weight[i] = min;
                i++;
            }
            included[k] = 1;
        }

        // printing MST
        int cost = 0;
        cout << "Minimum Spanning Tree (Departments connected):\n";
        for (int i = 0; i < V - 1; i++)
        {
            cout << t[0][i] << " - " << t[1][i] << " : " << weight[i] << "m\n";
            cost += weight[i];
        }
        cout << "Total Distance of MST: " << cost << " meters\n";
    }
};

int main()
{
    int matrix[V][V] = {
        {0, 10, 15, 0, 0, 0, 0},
        {10, 0, 0, 12, 0, 0, 0},
        {15, 0, 0, 13, 10, 0, 0},
        {0, 12, 13, 0, 0, 9, 0},
        {0, 0, 10, 0, 0, 8, 7},
        {0, 0, 0, 9, 8, 0, 6},
        {0, 0, 0, 0, 7, 6, 0}};

    krushkal k(matrix);

    k.findMST();
    return 0;
}
