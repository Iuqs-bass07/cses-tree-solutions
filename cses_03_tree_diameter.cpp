#include <bits/stdc++.h>
using namespace std;
#define int long long
using pi = pair<int, int>;

pi bfs(int node, vector<vector<int>> &graph){
    int n = graph.size()-1;
    vector<int> vis(n+1, 0);
    queue<pi> q;
    q.push({node, 0});
    vis[node] = 1;
    
    pi ans = {node, 0};
    while(!q.empty()){
        
        ans = q.front();
        int node = ans.first;
        int d = ans.second;
        q.pop();
        
        for(auto it: graph[node]){
            if(!vis[it]){
                q.push({it, d+1});
                vis[it] = 1;
            }
        }
    }
    return ans;
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
	
	pi end1 = bfs(1, graph);
	pi end2 = bfs(end1.first, graph);
	
	cout<<end2.second;
	return 0;
}