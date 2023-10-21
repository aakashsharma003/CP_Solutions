//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int node, vector<int> &vis,vector<int> &pathvis, vector<int> adj[]){
        vis[node] = 1;
        pathvis[node] = 1;
        // traverse the adjacent nodes 
        for(auto it: adj[node]){
            // when the node is not visited
            if(!vis[it]){
                if(dfs(it, vis, pathvis, adj)) return true;
            }
            // if the node has been previously visited 
            //  then it should be visited on the same path
            else if(pathvis[it] == 1){
                return true;
            }
        }
        pathvis[node] = 0;
        
        return false;
    }

	bool isPossible(int v,int p, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int>vis(v,0);
        vector<int>pathvis(v,0);
        vector<int>adj[v];
        
       for(auto &it: prerequisites){
           adj[it.first].push_back(it.second);
       }
        
        
        for(int i = 0;i < v;i++){
            if(!vis[i]){
                if(dfs(i, vis, pathvis, adj)){
                    return false;
                }
            }
        }
        return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends