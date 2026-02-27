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