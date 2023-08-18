class Solution {
public:
    int findWays(vector<int>& arr, int k){
	
      int n = arr.size();
	  vector<vector<int>>dp(n,vector<int>(k+1,0));
      if(arr[0] == 0)  dp[0][0] = 2;
      else
      dp[0][0] = 1;

    if(arr[0] != 0 && arr[0] <= k) dp[0][arr[0]] = 1;

    for(int indx =1;indx<n;indx++){
        for(int sum =0;sum <= k;sum++){
            int notpick = dp[indx-1][sum];

            int pick = 0;
            if(arr[indx] <= sum)
            pick += dp[indx-1][sum-arr[indx]];
              
            dp[indx][sum] = (pick + notpick);
        }
    }
    return dp[n-1][k];
   }

    int countPartitions(int n, int d, vector<int> &arr) {
    
    int totalSum = 0;
    for(int i =0;i<n;i++)
    totalSum += arr[i];
    //edge cases 
        //(1) fraction m nhi ana chahiye target sum and 
        //(2) should be positive
    if((totalSum - d) < 0 || (totalSum - d) % 2 != 0) return 0;
   
	return findWays(arr,(totalSum-d)/2);
    
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n,target,nums);
    }
};