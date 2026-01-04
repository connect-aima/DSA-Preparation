#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// int primMST(int V, vector<vector<pair<int,int>>> &adj) {//node,weight
//     priority_queue<
//                     pair<int,int>, //what we store//weight,node
//                     vector<pair<int,int>>,//container
//                     greater<>//min heap
//                     > pq;
//     vector<bool> inMST(V, false);

//     int mstCost = 0;
//     pq.push({0, 0}); // {weight, node}

//     while (!pq.empty()) {
//         auto [weight, u] = pq.top();
//         pq.pop();

//         if (inMST[u]) continue;

//         inMST[u] = true;
//         mstCost += weight;

//         for (auto &[v, w] : adj[u]) {//{{1,10}{}{}}
//             if (!inMST[v]) {
//                 pq.push({w, v});
//             }
//         }
//     }
//     return mstCost;
// }
int main() {
    
    return 0;
}