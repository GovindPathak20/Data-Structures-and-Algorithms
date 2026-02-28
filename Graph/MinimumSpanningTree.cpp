// Algorithms: Minimum Spanning Tree (MST)
// Undirected Graph:
// 0 -> [1,2], [3,6]
// 1 -> [0,2], [3,8], [4,5], [2,3]
// 2 -> [1,3], [4,7]
// 3 -> [0,6], [1,8]
// 4 -> [1,5], [2,7]
// 1. We will take a visited array to mark all the nodes in the undirected graph as unvisited
// 2. We will take a min heap to store the (wt, node, parent)
// 3. Add the first node in the min heap with weight 0 and parent -1 (0, 0, -1) and mark the first node as visited
// 4. Now look at all the nodes that are directly connected to 0 and add them in the min heap with their weight and their parent -> eg: (2, 1, 0) and (1,2,0)
// 5. Now update the MST list and the edge weight sum 
// MST = [(0,2)] sum = 1
// 6. Now pop the top element from the min heap and mark it as visited -> (1,2,0) is popped and marked as visited
// 7. Now look at all the nodes that are directly connected to 2 and add them in the min heap with their
// 8. Repeat the process until the min heap is empty

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> adj[n];
    for(int i=0; i<m; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    int ans = 0;
    vector<int> vis(n, 0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 0});
    while(!pq.empty()){
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(vis[node]){
            continue;
        }
        vis[node] = 1;
        ans += wt;
        for(auto it : adj[node]){
            int child = it.first;
            int edW = it.second;
            if(!vis[child]){
                pq.push({edW, child});
            }
        }
    }
    cout << ans << endl;
}

// Input:
// 3 3
// 0 1 5
// 1 2 3
// 0 2 1

// Time and Space Complexity:
// Time Complexity: O((V + E) log V) where V is the number of vertices and E is the number of edges in the graph. This is because we are using a priority queue to store the edges and we are processing each edge at most once.
// Space Complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph. This is because we are storing the graph in an adjacency list and we are also using a visited array to keep track of the visited nodes.