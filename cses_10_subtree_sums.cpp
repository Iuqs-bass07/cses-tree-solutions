#include<bits/stdc++.h>
using namespace std;
#define int long long

// int sz = 2*1e5+5;

vector<vector<int>> graph;
vector<int> st, en, flat, nums;
int timer = 0;

void dfs(int node, int par){
    
    flat[timer] = nums[node];
    st[node] = timer++;
    
    for(auto ch: graph[node]){
        
        if(ch != par){
            dfs(ch, node);
        }
    }
    flat[timer] = nums[node];
    en[node] = timer++;
}

class SegmentTree{
 
public:
  vector<int> seg;
  SegmentTree(vector<int> nums){
      int n = nums.size();
      seg.resize(4*n+5);
  }
  
  int build(int ind, int low, int high, vector<int> &nums){
      
      if(low == high){
          return seg[ind] = nums[low];
      }
      
      int mid = (low + high)>>1;
      int left = build(2*ind+1, low, mid, nums);
      int right = build(2*ind+2, mid+1, high, nums);
      
      return seg[ind] = seg[2*ind+1] + seg[2*ind+2];
  }
  
  void update(int ind, int low, int high, int idx, int val){
      if(low == high){
          seg[ind] = val;
          return;
      }
      
      int mid = (low + high)>>1;
      
      if(idx <= mid){
          update(2*ind+1, low, mid, idx, val);
      }
      else{
          update(2*ind+2, mid+1, high, idx, val);
      }
      seg[ind] = seg[2*ind+1] + seg[2*ind+2];
  }
  
  int query(int ind, int low, int high, int l, int r){
      
      if(l > high || r < low) return 0;
      if(low >= l && high <= r) return seg[ind];
      int mid = (low + high)>>1;
      
      return query(2*ind+1, low, mid, l, r) + query(2*ind+2, mid+1, high, l, r);
  }
};

int32_t main(){
    
    int n, m;
    cin>>n>>m;
    
    st.resize(n);
    en.resize(n);
    nums.resize(n);
    flat.resize(2*n);
    graph.resize(n);
    
    
    for(int i = 0; i<n; i++){
        cin>>nums[i];
    }
    
    for(int i = 1; i<n; i++){
        int u, v;
        cin>>u>>v;
        u--;
        v--;
        
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    
    dfs(0, -1);
    SegmentTree tree(flat);
    
    tree.build(0, 0, 2*n-1, flat);
    
    for(int i = 1; i<=m; i++){
        
        int type;
        cin>>type;
        
        if(type == 2){
            int node;
            cin>>node;
            node--;
            
            cout<<tree.query(0, 0, 2*n-1, st[node], en[node])/2<<endl;
        }
        else{
            int node, val;
            cin>>node>>val;
            node--;
            
            tree.update(0, 0, 2*n-1, st[node], val);
            tree.update(0, 0, 2*n-1, en[node], val);
        }
    }
    return 0;
}
 
 
