class Solution {
public:
    int solve(int indx,vector<int>&coins,int target,vector<vector<int>>&dp){
         
        if(indx == 0) return target % coins[0] == 0;
        
        
        if(dp[indx][target] != -1) return dp[indx][target];
        
        int notTake = solve(indx-1, coins, target,dp);
        
        int take = 0;
        
        if(coins[indx] <= target)
            take = solve(indx, coins,target-coins[indx],dp);
        
        return dp[indx][target] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
          int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(n-1,coins,amount,dp);
    }
};