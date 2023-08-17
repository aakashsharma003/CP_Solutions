//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   int solve(int indx,int w,int *val,int *wt,vector<vector<int>>&dp){
       if(indx == 0){
        if(w % wt[0] == 0) return val[0]*(w/wt[0]);
        else if(wt[0] < w) return val[0];
        return 0;
       }
       if(dp[indx][w] != -1) return dp[indx][w];
       int notpick = solve(indx-1,w,val,wt,dp);
       int pick = 0;
       if(wt[indx] <= w)
          pick = val[indx] + solve(indx,w-wt[indx],val,wt,dp);
          
       return dp[indx][w] = max(pick,notpick);
   }
    int knapSack(int n, int w, int val[], int wt[])
    {
       vector<vector<int>>dp(n,vector<int>(w+1,-1));
        return solve(n-1,w,val,wt,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends