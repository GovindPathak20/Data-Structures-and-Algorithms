// Implementation of Bellman-Ford algorithm to find the shortest path from a source vertex to all other vertices in a graph.
// Example graph:
// (u, v, wt)
// (3, 2, 6)
// (5, 3, 1)
// (0, 1, 5)
// (1, 5, -3)
// (1, 2, -2)
// (3, 4, -2)
// (2, 4, 3)
// Edges of a directed graph could be given in any particular order.
// 1. Relax all the edges (N-1) times sequentially.
// 2. Relax: (dis[u] + wt < dis[v]) => dis[v] = dis[u] + wt
// 3. Initially take a distance array and initialize all the vertices with infinity except the source vertex which is initialized with 0.
// 4. N-1 iterations means we need to perform the relaxation process on each edge and this process will be done (N-1) times.
// Questions: 
// Q1. Why are we having (N-1) iterations in the Bellman-Ford algorithm?
// Q2. How to detect negative weight cycles in a graph using the Bellman-Ford algorithm?
// A1. The reason we perform (N-1) iterations in the Bellman-Ford algorithm is that in a graph with N vertices, the longest possible path without a cycle can have at most (N-1) edges. Therefore, after (N-1) iterations of edge relaxation, we can guarantee that we have found the shortest path from the source vertex to all other vertices in the graph, as any further relaxation would not yield a shorter path.
// A2. After performing (N-1) iterations of edge relaxation, we can perform one additional iteration to check if any distance can still be reduced. If we can still reduce the distance of any vertex, it means there is a negative weight cycle in the graph.

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> adj[n];
    for(int i=0; i<m; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    int src;
    cin >> src;
    vector<int> dis(n, 1e9);
    dis[src] = 0;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n; j++){
            for(auto it : adj[j]){
                int v = it.first;
                int wt = it.second;
                if(dis[j] + wt < dis[v] && dis[j] != 1e9){
                    dis[v] = dis[j] + wt;
                }
            }
        }
    }
    // Check for negative weight cycle
    for(int j=0; j<n; j++){
        for(auto it : adj[j]){
            int v = it.first;
            int wt = it.second;
            if(dis[j] + wt < dis[v] && dis[j] != 1e9){
                cout << "Negative weight cycle detected!" << endl;
                return 0;
            }
        }
    }
    for(int i=0; i<n; i++){
        if(dis[i] == 1e9){
            cout << "Distance from source to vertex " << i << " is: " << "INF" << endl;
        } else {
            cout << "Distance from source to vertex " << i << " is: " << dis[i] << endl;
        }
    }
    return 0;
}

// Input:
// 6 7
// 3 2 6
// 5 3 1
// 0 1 5
// 1 5 -3
// 1 2 -2
// 3 4 -2
// 2 4 3
// 0

// Time Complexity: O(N*M) where N is the number of vertices and M is the number of edges in the graph.
// Space Complexity: O(N) for the distance array.