// Dijkstra Algorithm implementation using set data structure
// Set data structure is used to store the (wt, node) pairs in sorted order based on the weight. This allows us to efficiently retrieve the node with the smallest weight at each step of the algorithm. The set also allows us to easily update the weight of a node if we find a shorter path to it, by removing the old pair and inserting the new pair with the updated weight.

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
    int src;
    cin >> src;
    vector<int> dis(n, 1e9);
    dis[src] = 0;
    set<pair<int,int>> st;
    st.insert({0, src});
    while(!st.empty()){
        auto it = *(st.begin());
        int d = it.first;
        int node = it.second;
        st.erase(it);
        for(auto it : adj[node]){
            int child = it.first;
            int wt = it.second;
            if(d + wt < dis[child]){
                if(dis[child] != 1e9){
                    st.erase({dis[child], child});
                }
                dis[child] = d + wt;
                st.insert({dis[child], child});
            }
        }
    }
    for(int i=0; i<n; i++){
        cout << dis[i] << " ";
    }

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

// Time Complexity:
// The time complexity of Dijkstra's algorithm using a set data structure is O((V + E) log V), where V is the number of vertices and E is the number of edges in the graph. This is because each vertex is processed once, and each edge is processed at most once, with the operations on the set taking logarithmic time.
// Space Complexity:
// The space complexity of Dijkstra's algorithm using a set data structure is O(V + E), where V is the number of vertices and E is the number of edges in the graph. This is because we need to store the adjacency list of the graph, which takes O(V + E) space, and the set data structure, which can hold at most V elements in the worst case.
