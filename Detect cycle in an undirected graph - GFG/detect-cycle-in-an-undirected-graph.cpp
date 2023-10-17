//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool detectCycle(int src,int vis[],vector<int>adj[]){
        vis[src] = 1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto adjNode: adj[node]){
                if(!vis[adjNode]){
                    q.push({adjNode,node});
                    vis[adjNode] = 1;
                }
                else if(adjNode != parent){
                    return true;
                }
            }
        }
        
        return false;
    }
  
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
     
        int vis[v] = {0};
        
        bool flag = false;
        for(int i =0;i<v;i++){
            if(!vis[i]){
                flag = detectCycle(i,vis,adj);
            }
            if(flag) return true;
        }
            
      return flag;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends