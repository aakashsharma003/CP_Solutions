class Solution {
public:
    int change(int amount, vector<int>& coins) {
          int n = coins.size();
          vector<vector<int>>dp(n,vector<int>(amount+1,0));
        
        for(int target = 0;target<=amount;target++){
            dp[0][target] = (target%coins[0] == 0);
        }
        
        for(int indx = 1;indx<n;indx++){
            for(int target = 0;target <= amount;target++){
                      
               int notTake = dp[indx-1][target];
        
               int take = 0;
        
               if(coins[indx] <= target)
               take = dp[indx][target-coins[indx]];
        
               dp[indx][target] = take + notTake;  
            }
        }
        
     return dp[n-1][amount];
    }
};