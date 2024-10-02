#include<bits/stdc++.h>
using namespace std;

class BinaryLifting {
public:
    vector<vector<int>> dp;
    int maxLevel;
    
    BinaryLifting(int n, vector<int> &parent) {
        int m = ceil(log2(n));
        maxLevel = m + 1;
        dp.resize(maxLevel, vector<int>(n + 1, -1));
        
    }
    
    void build(int n, vector<int> &parent) {
        
        for (int i = 1; i <= n; i++) {
            dp[0][i] = parent[i];
        }
        
        for (int j = 1; j < maxLevel; j++) {
            for (int node = 1; node <= n; node++) {
                if (dp[j-1][node] != -1) {
                    dp[j][node] = dp[j-1][dp[j-1][node]];
                }
            }
        }
    }
    
    int kth(int node, int k) {
        for (int i = 0; i < maxLevel; i++) {
            if (k & (1 << i)) {
                node = dp[i][node];
                if (node == -1) break;
            }
        }
        return node;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> parent(n + 1, -1);
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        parent[i] = x;
    }
    
    BinaryLifting tree(n, parent);
    tree.build(n, parent);
    
    while (q--) {
        int node, k;
        cin >> node >> k;
        cout << tree.kth(node, k) << endl;
    }
    
    return 0;
}
