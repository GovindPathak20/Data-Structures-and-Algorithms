// Topological Sorting (DFS):
// 1. Linear ordering of vertices such that if there is an edge between u & v, u appears before v in that ordering
// 2. It only exists on DAG (Directed Acyclic Graph)

// Example Graph:
// 0 -> []
// 1 -> []
// 2 -> [3]
// 3 -> [1]
// 4 -> [0, 1]
// 5 -> [0, 2]

// Valid Topological Sort Orderings:
// 5, 4, 2, 3, 1, 0
// 4, 5, 2, 3, 1, 0

#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, vis, adj, st);
        }
    }
    st.push(node);
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> vis(n, 0);
    stack<int> st;
    vector<int> ans;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i, vis, adj, st);
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;

    return 0;
}

// Space Complexity: O(n) + O(n) (stack + visited array)
// Time Complexity: O(V + E)

// Input
// 6 6
// 5 2
// 2 3
// 3 1
// 4 1
// 4 0
// 5 0