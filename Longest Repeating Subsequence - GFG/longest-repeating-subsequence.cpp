//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int f(int i,int j,string &s,vector<vector<int>>&dp){ 
          if(i < 0 || j < 0) return 0;
          if(dp[i][j] != -1) return dp[i][j];
          if(s[i] == s[j] && i !=  j)  return dp[i][j] = 1 + f(i-1,j-1,s,dp);
          
          return dp[i][j] = max(f(i,j-1,s,dp),f(i-1,j,s,dp));
    } 
	
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.size();
		    vector<vector<int>>dp(n,vector<int>(n,-1));
            return f(n-1,n-1,str,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends