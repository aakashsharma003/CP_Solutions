//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
         int n = grid.size();
         int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i =0;i <grid.size();i++){
            for(int j = 0; j < grid[0].size();j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
            }
        }
        
        int time = 0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
             int r = q.front().first.first;
             int c = q.front().first.second;
             int t = q.front().second;
             q.pop();
             
             time = max(time,t);
            for(int i = 0;i< 4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                
                if(0 <= nrow && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol] = 2;
                }
            }
         }
        
          for(int i = 0;i < n;i++){
             for(int j = 0;j < m;j++){
                 if(vis[i][j] != 2 && grid[i][j] == 1){
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