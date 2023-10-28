//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(int node, int vis[], stack<int>&stk, vector<pair<int,int>>adj[]){
        vis[node] = 1;
        
        for(auto &it: adj[node]){
            if(!vis[it.first]){
                dfs(it.first, vis, stk, adj);
            }
        }
       stk.push(node);
       return;
    }
  
  
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        
        vector<pair<int,int>>adj[n];
        vector<int>dis(n, 1e9);
        for(auto v: edges){
            adj[v[0]].push_back({v[1],v[2]});
        }
        
        // topoSort
        int vis[n] = {0};
        
        stack<int>stk;
        
        for(int i = 0;i < n;i++){
         if(!vis[i]){
            dfs(i, vis, stk, adj);
         }
        }
        
        int src = 0;
        
        dis[src] = 0;
        
        while(!stk.empty()){
            int node = stk.top();
            stk.pop();
            int d = dis[node];
            
            for(auto &it: adj[node]){
                dis[it.first] = min(dis[it.first], d + it.second);
            }
        }
        
        for(int i = 0;i < n;i++){
            if(dis[i] >= 1e9){
                dis[i] = -1;
            }
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends