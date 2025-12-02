// DSC_119_question.cpp
// 119. Making Wired Connections (minimum number of operations to connect all computers)
// Given n nodes and edges, determine min operations (extra edges) to make graph connected.
// If edges < n-1 return -1. Else count components using DSU and return components-1.

#include <bits/stdc++.h>
using namespace std;
struct DSU {
    vector<int> p, r;
    DSU(int n):p(n),r(n,0){ iota(p.begin(), p.end(), 0); }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    void unite(int a,int b){
        a=find(a); b=find(b); if(a==b) return;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a; if(r[a]==r[b]) r[a]++;
    }
};
int makeConnected(int n, vector<pair<int,int>>& connections){
    if(connections.size() < n-1) return -1;
    DSU d(n);
    for(auto &e: connections) d.unite(e.first, e.second);
    int comps=0;
    for(int i=0;i<n;i++) if(d.find(i)==i) comps++;
    return comps-1;
}
int main(){
    vector<pair<int,int>> conn = {{0,1},{0,2},{0,3}};
    cout<<makeConnected(4, conn)<<"\n"; // 0 already connected
}
