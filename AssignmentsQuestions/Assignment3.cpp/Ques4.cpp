#include <iostream>
using namespace std;
#include <queue>
#include <vector>
#include <list>
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
    void addEdges(int u, int v)
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
        cout <<endl;
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
   graph g(5); // 5 intersections: A(0), B(1), C(2), D(3), E(4)

    // Add edges
    g.addEdges(0, 1); // A-B
    g.addEdges(0, 2); // A-C
    g.addEdges(1, 3); // B-D
    g.addEdges(2, 4); // C-E

    g.bfs(0,vis); // run BFS
    fill(vis.begin(), vis.end(), false);
    g.dfs(0,vis); // run DFS

    return 0;
}
