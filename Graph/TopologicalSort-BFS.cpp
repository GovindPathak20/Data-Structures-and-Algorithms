// Topological Sorting (BFS):
// 1. Linear ordering of vertices such that if there is an edge between u & v, u appears before v in that ordering
// 2. It only exists on DAG (Directed Acyclic Graph)
// 3. Kahn's Algorithm

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

// Kahn's Algorithm:
// 1. Find the indegree of all the nodes and store that in an array
// 2. Take a queue and insert all the nodes in the queue whose indegree is 0
// 3. Take these nodes out of the queue one by one and decrement the indegree of the adjacent nodes
// 4. If the indegree of the adjacent nodes become 0 then simply insert these nodes inside the queue as the nodes which will be coming in ordering before them would have already been taken out

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> adj[n];
    vector<int> indegree(n, 0);
    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;
    for(int i=0; i<n; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;

    return 0;
}

// Space Complexity: O(n) + O(n) (indegree array + queue)
// Time Complexity: O(V + E) (Same time complexity as BFS)

// Input
// 6 6
// 5 2
// 2 3
// 3 1
// 4 1
// 4 0
// 5 0