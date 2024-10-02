#include <bits/stdc++.h>
using namespace std;


int dfs(int node, vector<int> &count, vector<int> &vis, vector<vector<int>> &graph){
    
    if(vis[node] == 1) return 0;
    
    vis[node] = 1;
    count[node] = 1;
    
    for(auto it: graph[node]){
        if(vis[it] == 0){
            count[node] += dfs(it, count, vis, graph);
        }
    }
    return count[node];
}

int dfs(int node, vector<int> &count, vector<vector<int>> &graph){
    
    // if(vis[node] == 1) return 0;
    
    // vis[node] = 1;
    count[node] = 1;
    
    for(auto it: graph[node]){
        count[node] += dfs(it, count, graph);
    }
    return count[node];
}

int32_t main() {
	
	int n;
	cin>>n;
	
	vector<vector<int>> graph(n+1);
	for(int i = 2; i<=n; i++){
	    
	    int x;
	    cin>>x;
	    graph[x].push_back(i);
	}
	
	
	vector<int> count(n+1, 0);
	vector<int> vis(n+1, 0);
	
	dfs(1, count, graph);
	
	for(int i = 1; i<= n; i++){
	    cout<<count[i]-1<<" ";
	}
	return 0;
}