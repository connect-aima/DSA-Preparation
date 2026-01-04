#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;
class graph
{
public:
    int V;
    list<int> *l; // declared list
    graph(int v)
    {
        V = v;
        l = new list<int>[V]; // initizalized list with size equale of no of vertices
    }
    void addEdge(int u, int v)
    {
        l[u].push_back(v); // 0->1
        l[v].push_back(u); // 1->0
    }
    void bfs(int start, vector<bool> &vis)
    {
        queue<int> q;
        q.push(start);
        vis[start] = true;
        while (q.size() > 0)
        {
            int u = q.front();
            q.pop();
            cout << u << " ";
            for (int v : l[u])
            {
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    // if graph is disconnected use following code
    void bfsDisconnected()
    {
        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                bfs(i, vis);
            }
        }
    }
    void dfs(int u, vector<bool> &vis)
    {
        cout << u << " ";
        vis[u] = true;
        for (int v : l[u])
        {
            if (!vis[v])
            {
                dfs(v, vis);
            }
        }
    }
};
int main()
{
    vector<bool> vis(5, false);
    graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    // cout << "BFS" << endl;
    // g.bfs(0,vis);
    cout << "DFS" << endl;
    g.dfs(0, vis);

    return 0;
}