// To write DisjointSet Union By using Union By Rank Method
// 1. Initially we will take two arrays => rank and parent and initialize them
// 2. Initially each node will be having its rank as 0 and each node will be having its parent as itself
// 3. Pseudo code for finding Union(u,v)
//    i. Find the ultimate parent of u and v, let's say the ultimate parent are -> pu and pv
//    ii. Find the rank of pu and pv
//    iii. Connect smaller rank parent to larger rank parent always
//    iv. Update the parent of the smaller rank parent node (if the rank of both parent nodes are equal then increment the rank of any parent and connect them)
//    v. If the rank of any one parent node is already higher then don't need to update the rank of any parent node just connect the lower rank parent node with the higher one and just update the parent of lower rank parent node
//    vi. We will apply path compresion and will only keep track of the ultimate parent for each node -> (rank will not be reduced while doing path compresion)
// 4. Time Complexity - Union(u,v) -> O(4 * alpha) => as good as O(constant)
// 5. Path Compresion Pseudo Code:
//    i. findParent(u){
        //     if u == parent[u]{
        //         return u;
        //     }
        //     return findParent(parent[u])
        // }

#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent, rank;
    
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findParent(int u){
        if(parent[u] == u){
            return u;
        }
        int ulp_u = findParent(parent[u]);
        parent[u] = ulp_u;
        return parent[u];
    }

    void unionByRank(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
};

int main(){
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    if(ds.findParent(3) == ds.findParent(7)){
        cout << "Same Parent" << endl;
    }else{
        cout << "Not Same Parent" << endl;
    }

    ds.unionByRank(3, 7);
    if(ds.findParent(3) == ds.findParent(7)){
        cout << "Same Parent" << endl;
    }else{
        cout << "Not Same Parent" << endl;
    }

    return 0;
}

// Time Complexity: O(4 * alpha) => O(constant)
