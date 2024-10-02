#include <bits/stdc++.h>
using namespace std;
#define int long long

int bfs(int node, int n, vector<int> &ans, vector<vector<int>> &graph){
    
    vector<int> dist(n+1, -1);
    queue<int> q;
    q.push(node);

    dist[node] = 0;
    ans[node] = max(ans[node], dist[node]);
    int res = node;
    while(!q.empty()){
        
        int node = q.front();
        res = q.front();
        q.pop();
        
        for(auto it: graph[node]){
            
            if(dist[it] == -1){
                dist[it] = dist[node] + 1;
                ans[it] = max(ans[it], dist[it]);
                q.push(it);
            }
        }
    }
    return res;
}
int32_t main() {
	
	int n;
	cin>>n;
	
	vector<vector<int>> graph(n+1);
	for(int i = 1; i<=n-1; i++){
	    int u, v;
	    cin>>u>>v;
	    graph[u].push_back(v);
	    graph[v].push_back(u);
	}
	
	vector<int> ans(n+1, -1);
	int end1 = bfs(1, n, ans, graph);
	int end2 = bfs(end1, n, ans, graph);
	bfs(end2, n, ans, graph);
	
	for(int i = 1; i<= n; i++){
	    cout<<ans[i]<<" ";
	}
	return 0;
}