#include<iostream>
using namespace std;
#define n 7
class MazeGraph{
    public:
    int graph[n][n];
    int visited[n];

    MazeGraph(int g[n][n]){
        for(int i = 0; i<n; i++){
            visited[i] = 0;
            for(int j=0; j<n; j++){
                graph[i][j] = g[i][j];
            }
        }
    }

    void DFS(int start){

    }

    void BFS(int start){

    }
};

int main(){
    int G[n][n] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 0, 0},
        {0, 1, 0, 1, 1, 0, 0},
        {0, 1, 1, 0, 1, 0, 1},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 1, 0, 0, 1, 1, 0},
        {0, 1, 1, 1, 1, 0, 1}};
    // Creating an object of MazeGraph
    MazeGraph maze(G);
    // Performing DFS and BFS traversals
    maze.DFS(3);
    maze.BFS(3);
    return 0;
    return 0;
}