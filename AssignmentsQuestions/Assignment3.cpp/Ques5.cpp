#include <bits/stdc++.h>
using namespace std;

// Disjoint set data structure
class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int i) {
        return (parent[i] == i) ? i : (parent[i] = find(parent[i]));
    }

    void unite(int x, int y) {
        int s1 = find(x), s2 = find(y);
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) parent[s1] = s2;
            else if (rank[s1] > rank[s2]) parent[s2] = s1;
            else parent[s2] = s1, rank[s1]++;
        }
    }
};

// comparator to sort edges by weight
bool comparator(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

int kruskalsMST(int V, vector<vector<int>> &edges, vector<pair<string, string>> &mstEdges) { //fixed: add mstEdges to store MST each edges has src,destination respectively
    // Sort all edges by weight       ->each edges has src,des,weight respectively
    sort(edges.begin(), edges.end(), comparator);

    cout << "Edges sorted by weight:\n"; //fixed
    for (auto &e : edges) {
        cout << char('A' + e[0]) << " - " << char('A' + e[1]) << " : " << e[2] << "\n"; //fixed
    }
    cout << "\n";

    DSU dsu(V);
    int cost = 0, count = 0;

    cout << "Kruskal's Algorithm Steps:\n"; //fixed
    for (auto &e : edges) {
        int x = e[0], y = e[1], w = e[2];

        // Check for cycle
        if (dsu.find(x) != dsu.find(y)) {
            dsu.unite(x, y);
            cost += w;
            mstEdges.push_back({string(1, char('A' + x)), string(1, char('A' + y))}); //fixed src,des
            cout << "Accepted edge: " << char('A' + x) << " - " << char('A' + y) << " : " << w << "\n"; //fixed
            count++;
            if (count == V - 1) break;
        } else {
            cout << "Rejected edge (cycle): " << char('A' + x) << " - " << char('A' + y) << " : " << w << "\n"; //fixed
        }
    }
    return cost;
}

int main() {
    // Map nodes A-G to 0-6
    int V = 7;

    // Edges {src, dest, weight}
    vector<vector<int>> edges = {//A->0, ONWARDS TILL G {0 1 2 3 4 5 6}
        {0, 2, 15}, // A-C
        {1, 2, 20}, // B-C
        {1, 3, 25}, // B-D
        {2, 4, 30}, // C-E
        {3, 4, 35}, // D-E
        {4, 5, 40}, // E-F
        {4, 6, 45}, // E-G
        {5, 6, 50}  // F-G
    };

    vector<pair<string, string>> mstEdges; //fixed: store MST edges
    int totalCost = kruskalsMST(V, edges, mstEdges);

    cout << "\nMinimum Spanning Tree Edges:\n"; //fixed
    for (auto &p : mstEdges) {
        cout << p.first << " - " << p.second << "\n";
    }

    cout << "\nTotal distance of MST: " << totalCost << " miles\n"; //fixed

    return 0;
}
