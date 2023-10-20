//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   bool dfsCheck(int node, vector<int> &vis, vector<int> &pathVis, vector<int> adj[]){
       
       vis[node] = 1;
       pathVis[node] = 1;
      
       for(auto it: adj[node]){
           if(!vis[it]){
               if(dfsCheck(it, vis, pathVis, adj) == true){
                   return true;
               }
           }
             // if anyone givesme false meanse it has a cycle   
           else if(pathVis[it] == 1){
               return true;
           }
       }
       pathVis[node] = 0;
       return false;
  }

    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        // code here
        vector<int>safeNodes;
        vector<int>vis(v,0);
        vector<int>pathVis(v,0);
        
        for(int i = 0;i < v;i++){
            if(!vis[i]){
                dfsCheck(i, vis, pathVis, adj);
            }
        }
        
        for(int i =0;i<v;i++){
            if(pathVis[i] == 0) safeNodes.push_back(i);
            // cout<<pathVis[i]<<" ";
        }
        
        return safeNodes;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends