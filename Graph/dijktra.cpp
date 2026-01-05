// #include <iostream>
// #include <vector>
// #include <queue>
// # include <climits>
// using namespace std;
// vector<int> dijkstra(int V, 
//     vector<vector<pair<int,int>>> &adj, 
//     int src) {
//     priority_queue<
//     pair<int,int>, 
//     vector<pair<int,int>>, 
//     greater<>
//     > pq;
//     vector<int> dist(V, INT_MAX);

//     dist[src] = 0;
//     pq.push({0, src}); // {distance, node}

//     while (!pq.empty()) {
//         auto [d, u] = pq.top();
//         pq.pop();

//         if (d > dist[u]) continue;

//         for (auto &[v, w] : adj[u]) {
//             if (dist[u] + w < dist[v]) {
//                 dist[v] = dist[u] + w;
//                 pq.push({dist[v], v});
//             }
//         }
//     }
//     return dist;
// }
// int main() {
//     int V = 4;
//     vector<vector<pair<int,int>>> adj(V);

//     // adding edges (undirected graph)
//     adj[0].push_back({1, 1});
//     adj[0].push_back({2, 4});

//     adj[1].push_back({0, 1});
//     adj[1].push_back({2, 2});
//     adj[1].push_back({3, 6});

//     adj[2].push_back({0, 4});
//     adj[2].push_back({1, 2});
//     adj[2].push_back({3, 3});

//     adj[3].push_back({1, 6});
//     adj[3].push_back({2, 3});

//     int src = 0;
//     vector<int> result = dijkstra(V, adj, src);

//     cout << "Shortest distances from node " << src << ":\n";
//     for (int i = 0; i < V; i++) {
//         cout << "Node " << i << " -> " << result[i] << endl;
//     }
//     return 0;
// }