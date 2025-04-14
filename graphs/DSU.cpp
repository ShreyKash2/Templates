#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1,1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            
        }
    }
    int findRank(int node){
        return rank[node];
    }
    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 
int main() {
    
    //use either union by size or by rank
    // don't intermix
//*kruskal implementation*;

int v=9;
//vertex=9 lets suppose
vector<vector<int>> edges(v,vector<int>(3));
DisjointSet ds(v);
vector<pair<int,pair<int,int>>> edge2;
// to sort wrt to weight we, need pairs
for(int i=0;i<edges.size();i++){
    int wt=edges[i][0];int u=edges[i][1];int v=edges[i][2];
    edge2.push_back({wt,{u,v}});
}
int min_spanning_tree_sum=0;

sort(edge2.begin(),edge2.end());
for(auto p:edge2){
int wt=p.first;
int u=p.second.first;
int v=p.second.second;
if(ds.findUPar(u)!=ds.findUPar(v)){
    //different upper parent, different component
    min_spanning_tree_sum+=wt;
    ds.unionByRank(u,v);
}


}
	return 0;
}





