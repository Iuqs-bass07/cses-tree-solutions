#include<bits/stdc++.h>
using namespace std;

vector<int> depth;
vector<int> parent;
vector<vector<int>> graph;
vector<vector<int>> dp;
vector<int> prefix;

void dfs(int node, int par, int l) {
    depth[node] = l;
    parent[node] = par;

    for (auto it : graph[node]) {
        if (it != par) {
            dfs(it, node, l + 1);
        }
    }
}

void preprocess(int n) {
    
    
    for (int node = 1; node <= n; node++) {
        dp[node][0] = parent[node];
    }

    for (int j = 1; j < 21; j++) {
        for (int node = 1; node <= n; node++) {
            dp[node][j] = dp[dp[node][j - 1]][j - 1];
        }
    }
}

int lca(int u, int v) {
    if (depth[u] > depth[v]) {
        swap(u, v);
    }

    int diff = depth[v] - depth[u];
    for (int i = 20; i >= 0; i--) {
        if (diff & (1 << i)) {
            v = dp[v][i];
        }
    }

    if (u == v) return u;

    for (int i = 20; i >= 0; i--) {
        if (dp[u][i] != dp[v][i]) {
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    return dp[u][0];
}

void dfs_prefix(int node, int par){
    
    for(auto ch: graph[node]){
        
        if(ch != par){
            dfs_prefix(ch, node);
            prefix[node] += prefix[ch];
        }
    }
    return;
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    parent.resize(n + 1);
    depth.resize(n + 1);
    prefix.resize(n + 1);
    dp.resize(n + 1, vector<int>(21, 0));

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, 0, 0);
    preprocess(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        prefix[u]++;
        prefix[v]++;
        int lc = lca(u, v);
        prefix[lc]--;
        prefix[parent[lc]]--;
    }

    dfs_prefix(1, 0); 

    for (int i = 1; i <= n; i++) {
        cout << prefix[i] << " ";
    }

    return 0;
}
