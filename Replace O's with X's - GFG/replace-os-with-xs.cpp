//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dx[4] = {-1,0,+1,0};
    int dy[4] = {0,+1,0,-1};
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &mat){
        int n = mat.size();
        int m = mat[0].size();
        
        vis[row][col] = 1;
        
        for(int i = 0;i < 4;i++){
         int nrow = row + dx[i];
         int ncol = col + dy[i];
         
         if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && mat[nrow][ncol] == 'O' && !vis[nrow][ncol]){
            vis[nrow][ncol] = 1;
            dfs(nrow,ncol,vis,mat);
         }
            
      }
      
     return; 
    
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>>vis(n,vector<int>(m,0));
        // traversing  row wise boundary O's 
        
        for(int i = 0;i< n;i++){
            if(mat[i][0] == 'O' && !vis[i][0]){
                dfs(i, 0, vis, mat);
            }
            if(mat[i][m-1] == 'O' && !vis[i][m-1]){
                dfs(i, m-1, vis, mat);
            }
        }
        
        // traversing  column wise boundary O's
                
        for(int j = 0;j< m;j++){
            if(mat[0][j] == 'O' && !vis[0][j]){
                dfs(0, j, vis, mat);
            }
            if(mat[n-1][j] == 'O' && !vis[n-1][j]){
                dfs(n-1, j, vis, mat);
            }
        }
        
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(vis[i][j] == 0){
                    mat[i][j] = 'X';
                }
            }
        }
        
       return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends