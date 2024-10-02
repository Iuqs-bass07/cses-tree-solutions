#include <bits/stdc++.h>
using namespace std;
#define int long long

int sz[200005];
int indp[200005];
int outdp[200005];
vector<int> graph[200005];
int N;


//concept used are tree dp

//in dp will be the sum of all childs indp and their sizes
// indp[par] = sum(indp[ch] + sz[ch])

//out dp will be the total contribution from the parents
//outdp[node] = outdp[par] + (N-sz[node]) + (indp[par] - indp[child] - sz[node]);

// so in the end the total contribution from the node will be the sum of indp[i] and outdp[i]
    
void dfs1(int node, int par){
    
    sz[node] = 1;
    indp[node] = 0;
    
    for(auto it: graph[node]){
        if(it != par){
            dfs1(it, node);
            sz[node] += sz[it];
            indp[node] += indp[it] + sz[it];
        }
    }
}

void dfs2(int node, int par){
    
    if(par == -1){
        outdp[node] = 0;
    }
    else{
        outdp[node] = (outdp[par] + N - sz[node]) + (indp[par] - indp[node] - sz[node]);
    }
    
    for(auto it: graph[node]){
        if(it != par){
            dfs2(it, node);
        }
    }
}

int32_t main() {
	
	int n;
	cin>>n;
	
	N = n;
	
	for(int i = 1; i<=n-1; i++){
	    int u, v;
	    cin>>u>>v;
	    graph[u].push_back(v);
	    graph[v].push_back(u);
	}
	
	dfs1(1, -1);
	dfs2(1, -1);
	
	for(int i = 1; i<=N; i++){
	    cout<<indp[i] + outdp[i]<<" ";
	}
	return 0;
}