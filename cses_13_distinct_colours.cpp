#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

vector<vector<int>> graph;
vector<int> col;
vector<int> ans;


set<int> dfs(int node, int par){
    
    set<int> unique;
    unique.insert(col[node]);
    
    for(auto ch: graph[node]){
        if(ch != par){
            
            set<int> sub = dfs(ch, node);
            if(sub.size() > unique.size()) swap(sub, unique);
            for(auto it: sub){
                unique.insert(it);
            }
        }
    }
    ans[node] = unique.size();
    return unique;
}

int32_t main(){
    
    int n;
    cin>>n;
    graph.resize(n+1);
    ans.resize(n+1);
    col.resize(n+1);
    
    for(int i = 1; i<=n; i++){
        cin>>col[i];
    }
    
    for(int i = 1; i<n; i++){
        int u, v;
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    
    dfs(1, 0);
    for(int i = 1; i<=n; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}