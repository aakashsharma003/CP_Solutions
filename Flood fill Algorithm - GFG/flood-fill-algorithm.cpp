//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
     vector<vector<int>> bfs(vector<vector<int>>& image, int sr, int sc, int newColor) {
         
         int n = image.size();
         int m = image[0].size();
         vector<vector<int>>vis(n,vector<int>(m,0));
         queue<pair<int,int>>q;
         q.push({sr,sc});
         vis[sr][sc] = 1;
         
         while(!q.empty()){
             int row = q.front().first;
             int col = q.front().second;
             q.pop();
             
            if(row > 0 && image[row-1][col] == image[row][col] && !vis[row-1][col]){
                q.push({row-1,col});
                vis[row-1][col] = 1;
                
            }
            if(col > 0 && image[row][col-1] == image[row][col] && !vis[row][col-1]){
                q.push({row,col-1});
                vis[row][col-1] = 1;
            }
            if(col+1 < m && image[row][col+1] == image[row][col] && !vis[row][col+1]){
                q.push({row,col+1});
                vis[row][col+1] = 1;
            }
            if(row+1 < n && image[row+1][col] == image[row][col] && !vis[row+1][col]){
                q.push({row+1,col});
                vis[row+1][col] = 1;
            }
            
         }
         
         for(int i = 0;i < vis.size();i++){
             for(int j = 0;j < vis[0].size();j++){
                 if(vis[i][j] == 1){
                    image[i][j] = newColor;
                 }
             }
         }
        return image;
     }
     
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        return bfs(image,sr,sc,newColor);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends