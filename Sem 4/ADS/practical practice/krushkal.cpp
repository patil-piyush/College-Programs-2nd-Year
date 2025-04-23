#include<iostream>
#include<climits>
using namespace std;

#define V 7
#define INF INT_MAX

class krushkal{
    private: 
    int edges[3][9];
    int included[9];
    int set[8];
    int t[2][6];
    int weight[6];

    public:
    krushkal(int input[V][V]){
        for(int i=0; i<8; i++)
            set[i] = -1;
        for(int i = 0; i<9; i++){
            included[i] =0;
            edges[0][i] = 0;
            edges[1][i] = 0;
            edges[2][i] = 0;
        }

        int k=0;
        for(int i = 0; i<V; i++){
            for(int j = i+1; j < V; j++)
            {
                if(input[i][j]){
                    edges[0][k] = i+1;
                    edges[1][k] = j+1;
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
        int x= u, v=0;
        while(set[x] > 0) x=set[x];
        while(u!=x){
            v = set[u];
            set[u] = x;
            u = v;
        }
        return x;
    }

    void findMST(){
        int i=0,j,k=0,u,v,e=9,min;

        while(i < V-1){
            min = INF;
            for(j=0; j<e; j++){
                if(included[j] == 0 && edges[2][j]<min){
                    u = edges[0][j];
                    v = edges[1][j];
                    min = edges[2][j];
                    k=j;
                }
            }

            if(find(u) != find(v)){
                t[0][i] = u;
                t[1][i] = v;
                myUnion(find(u), find(v));
                weight[i] = min;
                i++;
            }
            included[k] = 1;
        }

        int total=0;
        for(int i = 0; i< V-1; i++){
            cout<<"from: "<<t[0][i]<<"  to: "<<t[1][i]<<" cost: "<<weight[i]<<endl;
            total += weight[i];
        }
        cout<<"Total: "<<total<<endl;
    } 
};

int main(){
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