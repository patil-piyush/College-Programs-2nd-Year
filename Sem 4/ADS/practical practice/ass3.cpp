#include <iostream>
#include <queue>
using namespace std;

#define n 7
queue<int> q;

class maze
{
private:
    int graph[n][n];
    int visited[n];

public:
    maze(int input[n][n])
    {
        for (int i = 0; i < n; i++)
        {
            visited[i] = 0;
            for (int j = 0; j < n; j++)
            {
                graph[i][j] = input[i][j];
            }
        }
    }

    void DFS(int start)
    {
        static int visit[n] = {0};
        if (visit[start] == 0)
        {
            cout << start << " ";
            visit[start] = 1;
            for (int v = 0; v < n; v++)
            {
                if (visit[v] == 0 && graph[start][v])
                {
                    DFS(v);
                }
            }
        }
    }

    void BFS(int start)
    {
        int i = start;
        int u = 0;
        cout << i << " ";
        visited[i] = 1;
        q.push(i);
        while (!q.empty())
        {
            u = q.front();
            q.pop();
            for (int v = 0; v < n; v++)
            {
                if (visited[v] == 0 && graph[u][v])
                {
                    visited[v] = 1;
                    cout<<v<<" ";
                    q.push(v);
                }
            }
        }
    }
};

int main()
{
    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};
    maze m(G);

    m.DFS(4);
    cout<<endl;
    m.BFS(4);
    return 0;
}