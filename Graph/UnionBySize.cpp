// To Write DisjointSet Union By using Union By Size Method
// 1. Initially we will take two arrays => size and parent array => each node will be having its size as 1 and each node will be having it's parent as itself only
// 2. Pseudo code for finding Union(u, v)
//    i. Find the ultimate parent of u and v, let's say the ultimate parent are -> pu and pv
//    ii. Find the size of pu and pv
//    iii. If the size of pu and pv are equal -> attach pu with pv and increment the size of pv (size[pv] = size[pv] + size[pu]) and now parent of pu will be pv
//    iv. Union(w, v) -> Find ultimate parent -> pw and pv -> attach pw to pv -> parent of pw will be pv and increment size of pv (size[pv] = size[pv] + size[pw])

#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> size, parent;
    
public:
    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findParent(int u){
        if(u == parent[u]) return u;
        int ulp_u = findParent(parent[u]);
        parent[u] = ulp_u;
        return parent[u];
    }

    void UnionBySize(int u, int v){
        int ulp_u = findParent(u);
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
    DisjointSet ds(7);
    ds.UnionBySize(1, 2);
    ds.UnionBySize(2, 3);
    ds.UnionBySize(4, 5);
    ds.UnionBySize(6, 7);
    ds.UnionBySize(5, 6);
    if(ds.findParent(3) == ds.findParent(7)){
        cout << "Same Parent" << endl;
    }else{
        cout << "Not Same Parent" << endl;
    }

    ds.UnionBySize(3, 7);
    if(ds.findParent(3) == ds.findParent(7)){
        cout << "Same Parent" << endl;
    }else{
        cout << "Not Same Parent" << endl;
    }

    return 0;
}

// Time Complexity: O(4 * alpha) => O(constant)
