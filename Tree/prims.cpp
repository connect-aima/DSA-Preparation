// #include <iostream>
// #include <vector>
// #include <queue>
// #include <tuple>
// using namespace std;

// struct Edge {
//     int u, v, w;
// };

// pair<int, vector<Edge>> primMST(
//     int V,
//     vector<vector<pair<int,int>>> &adj
// ) {
//     priority_queue<
//         tuple<int,int,int>,   // {weight, node, parent}
//         vector<tuple<int,int,int>>,
//         greater<>
//     > pq;

//     vector<bool> inMST(V, false);
//     vector<Edge> mstEdges;
//     int mstCost = 0;

//     pq.push({0, 0, -1}); // {weight, node, parent}

//     while (!pq.empty()) {
//         auto [weight, u, parent] = pq.top();
//         pq.pop();

//         if (inMST[u]) continue;

//         inMST[u] = true;
//         mstCost += weight;

//         if (parent != -1) {
//             mstEdges.push_back({parent, u, weight});//src des weight
//         }

//         for (auto &[v, w] : adj[u]) {
//             if (!inMST[v]) {
//                 pq.push({w, v, u});//weight src des
//             }
//         }
//     }

//     return {mstCost, mstEdges};
// }

// int main() {
//     int V = 5;
//     vector<vector<pair<int,int>>> adj(V);

//     // Lambda to add undirected edges
//     auto addEdge = [&](int u, int v, int w) {
//         adj[u].push_back({v, w});
//         adj[v].push_back({u, w});
//     };

//     addEdge(0, 1, 2);
//     addEdge(0, 3, 6);
//     addEdge(1, 2, 3);
//     addEdge(1, 3, 8);
//     addEdge(1, 4, 5);
//     addEdge(2, 4, 7);
//     addEdge(3, 4, 9);

//     pair<int, vector<Edge>> result = primMST(V, adj);

//     cout << "MST Cost: " << result.first << "\n";
//     cout << "MST Edges:\n";
//     for (auto &edge : result.second) {
//         cout << edge.u << " - " << edge.v << " (weight: " << edge.w << ")\n";
//     }

//     return 0;
// }
