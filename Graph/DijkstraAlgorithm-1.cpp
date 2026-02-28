// Dijkstra Algorithm implementation using priority queue

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> adj[n];
    for(int i=0; i<m; i++){
        int u,v,wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    int src;
    cin >> src;
    vector<int> dis(n, 1e9);
    dis[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});
    while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it : adj[node]){
            int child = it.first;
            int wt = it.second;
            if(d + wt < dis[child]){
                dis[child] = d = wt;
                pq.push({dis[child], child});
            }
        }
    }
    for(int i=0; i<n; i++){
        cout << dis[i] << " ";
    }
    cout << endl;

    return 0;
}

// Input:
// 5 6
// 0 1 2
// 0 2 4
// 1 2 1
// 1 3 7
// 2 4 3
// 3 4 2
// 0

// Why Dijkstra's algorithm is not suitable for negative weight edges?
// Dijkstra's algorithm is not suitable for negative weight edges because it relies on the principle of "greedy choice". The algorithm assumes that once a node's shortest path is determined, it will not change. However, if there are negative weight edges, it is possible for a shorter path to be found after a node has already been marked as visited, which can lead to incorrect results. In such cases, algorithms like Bellman-Ford are more appropriate as they can handle negative weight edges effectively
// 0 -> [1, -2] -> In this example the distance of the resultant node reduces in every iteration so it goes on into an infinite loop
// Time Complexity: O(E log V) where E is the number of edges and V is the number of vertices in the graph. This is because we are using a priority queue to store the edges and we are processing each edge at most once. The log V factor comes from the time taken to insert and remove elements from the priority queue.
// Space Complexity: O(V) where V is the number of vertices in the graph. This is because we are using a distance array to store the shortest distance from the source node to each vertex in the graph. Additionally, the priority queue can also hold up to O(V) elements in the worst case, but this is typically considered part of the space complexity of the algorithm.