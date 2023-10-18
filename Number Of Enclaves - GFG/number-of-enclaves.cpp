//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
           int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
    
         queue<pair<int,int>>q;
    
        for(int i = 0;i < n;i++){
            if(!vis[i][0] && grid[i][0] == 1)
            {
                vis[i][0] = 1;
                q.push({i,0});
            }
            if(!vis[i][m-1] && grid[i][m-1] == 1)
            {
                vis[i][m-1] = 1;
                q.push({i,m-1});
            }
        }
        
        for(int j = 0;j < m;j++){
            if(!vis[0][j] && grid[0][j] == 1)
            {
                vis[0][j] = 1;
                q.push({0,j});
            }
            if(!vis[n-1][j] && grid[n-1][j] == 1)
            {
                vis[n-1][j] = 1;
                q.push({n-1,j});
            }
        }
         
         int dx[4] = {-1,0,+1,0};
         int dy[4] = {0,+1,0,-1};
        
        
        while(!q.empty()){
              int row = q.front().first;
              int col = q.front().second;
              q.pop();
              for(int i = 0;i<4;i++){
                  int nrow = row + dx[i];
                  int ncol = col + dy[i];
                  
                  if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                      vis[nrow][ncol] = 1;
                      q.push({nrow,ncol});
                  }
              }
        }
        
        int cnt = 0;
        for(int i =0;i<n;i++){
            for(int j = 0;j < m;j++){
                if(vis[i][j] != 1 && grid[i][j] == 1){
                    cnt++;
                }
                // cout<<vis[i][j]<<" ";
            }
            // cout<<endl;
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends