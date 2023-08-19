//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
   int solve(int indx,int *price,int target,vector<vector<int>>&dp){
       
       if(indx == 0) return price[0]*target;
       
       if(dp[indx][target] != -1) return dp[indx][target];
       int notTake = 0 + solve(indx-1,price,target,dp);
       
       int take = -1e6;
       int rodlength = indx+1;
       if(rodlength <= target)
           take = price[indx] + solve(indx,price,target-rodlength,dp);
       
       return dp[indx][target] = max(take,notTake);
       
   }
  
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(n-1,price,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends