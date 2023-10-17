//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges.
   
    //  void bfs(vector<vector<int>>& grid,int row,int col,vector<vector<int>> &vis, int &time){
         
    //      int n = grid.size();
    //      int m = grid[0].size();
   
    //      q.push({row,col});
    //      vis[row][col] = 1;
    //      bool flag = false;
         
         
    //     return;
    //  }
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
         int n = grid.size();
         int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
         int time = 0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i =0;i<grid.size();i++){
            for(int j =0;j < grid[0].size();j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
            }
        }
        
        
        while(!q.empty()){
             int row = q.front().first.first;
             int col = q.front().first.second;
             time = q.front().second;
            //  flag = false;
             q.pop();
             
            if(row > 0 && grid[row-1][col] == 1 && !vis[row-1][col]){
                q.push({{row-1,col},time+1});
                vis[row-1][col] = 2;
                grid[row-1][col] = 2;
                
            }
            if(col > 0 && grid[row][col-1] == 1 && !vis[row][col-1]){
                q.push({{row,col-1},time+1});
                vis[row][col-1] = 2;
                grid[row][col-1] = 2;
            }
            if(col+1 < m && grid[row][col+1] == 1 && !vis[row][col+1]){
                q.push({{row,col+1},time+1});
                vis[row][col+1] = 2;
                grid[row][col+1] = 2;
            }
            if(row+1 < n && grid[row+1][col] == 1 && !vis[row+1][col]){
                q.push({{row+1,col},time+1});
                vis[row+1][col] = 2;
                grid[row+1][col] = 2;
            }
         }
        
          for(int i = 0;i < grid.size();i++){
             for(int j = 0;j < grid[0].size();j++){
                 if(grid[i][j] == 1){
                    return -1;
                 }
             }
         }
         return time;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends