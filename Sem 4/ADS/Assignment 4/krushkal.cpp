#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define V 7
#define I INT_MAX

class krushkal
{
public:
    int set[8];
    int edges[3][9];
    int include[8];
    int t[2][6]; // To store result MST: [0]=u, [1]=v
    int weight[6];

    krushkal(int input[V][V])
    {
        for (int i = 0; i < 8; i++)
            set[i] = -1;

        for (int i = 0; i < 9; i++)
        {
            include[i] = 0;
            edges[0][i] = edges[1][i] = edges[2][i] = 0;
        }

        int k = 0;
        for (int i = 0; i < V; i++)
        {
            for (int j = i + 1; j < V; j++)
            {
                if (input[i][j] != 0)
                {
                    edges[0][k] = i + 1;
                    edges[1][k] = j + 1;
                    edges[2][k] = input[i][j];
                    k++;
                }
            }
        }
    }


    void myUnion(int u, int v){
        if(set[u] < set[v]){
            set[u] += set[v];
            set[v] = u;
        }
        else{
            set[v] += set[u];
            set[u] = v;
        }
    }

    int find(int u){
        int x = u, v=0;
        while(set[x] > 0){
            x = set[x];
        }
        while(u != x){
            v = set[u];
            set[u] = x;
            u = v;
        }
        return x;
    }

    void findMST()
    {
        int i=0, min, k, u, v, e=9;
        while(i < V-1){
            min = I;
            for(int j = 0; j<9; j++){
                if(include[j] == 0 && edges[2][j]<min){
                    min = edges[2][j];
                    u = edges[0][j];
                    v = edges[1][j];
                    k=j;
                }
            }

            if(find(u) != find(v)){
                t[0][i] = u;
                t[1][i] = v;
                weight[i] = min;
                myUnion(find(u) , find(v));
                i++;
            }
            include[k]=1;
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