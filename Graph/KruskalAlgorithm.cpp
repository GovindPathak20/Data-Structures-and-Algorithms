// Implementation of Kruskal's algorithm to find the Minimum Spanning Tree (MST) of a graph.
// Algorithm:
// 1. Sort all edges in non-decreasing order of their weight.
// 2. Pick the smallest edge. Check if it forms a cycle with the spanning tree
//    formed so far. If it doesn't, include this edge. Else, discard it.
// 3. Repeat step 2 until there are (V-1) edges in the spanning tree, where V is the number of vertices in the graph.

#include<bits/stdc++.h>
using namespace std;

class DSU{
private:
    vector<int> parent, size;
public:
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u  = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> edges; // {weight, {u, v}}
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    // Sort edges based on weight
    sort(edges.begin(), edges.end());
    
    DSU dsu(n);
    int mst_weight = 0;
    vector<pair<int, int>> mst_edges; // To store the edges in the MST

    for(auto &edge : edges){
        int w = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if(dsu.findParent(u) != dsu.findParent(v)){
            dsu.unionBySize(u, v);
            mst_weight += w;
            mst_edges.push_back({u, v});
        }
    }

    cout << "Weight of the Minimum Spanning Tree: " << mst_weight << endl;
    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for(auto &edge : mst_edges){
        cout << edge.first << " -- " << edge.second << endl;
    }

    return 0;
}

// Input:
// 4 5
// 1 2 10
// 1 3 15
// 2 3 5
// 2 4 10
// 3 4 10

// Time Complexity: O(E log E) due to sorting the edges, where E is the number of edges.
// Space Complexity: O(V) for the DSU data structure, where V is the number of vertices.