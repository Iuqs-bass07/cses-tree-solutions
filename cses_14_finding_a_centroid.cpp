#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

vector<vector<int>> graph;
vector<int> sub;
int N;

void dfs(int node, int par){
    
    sub[node] = 1;
    for(auto ch: graph[node]){
        if(ch != par){
            dfs(ch, node);
            sub[node] += sub[ch];
        }
    }
}


int centroid(int node, int par){
    
    for(auto ch: graph[node]){
        if(ch != par){
            if(sub[ch] > N/2){
                return centroid(ch, node);
            }
        }
    }
    return node;
    
}
int32_t main(){
    
    int n;
    cin>>n;
    N = n;
    graph.resize(n+1);
    sub.resize(n+1);
    
    for(int i = 1; i<n; i++){
        int u, v;
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    
    dfs(1, 0);
    cout<<centroid(1, 0)<<endl;
    dfs(1, 0);
    
}