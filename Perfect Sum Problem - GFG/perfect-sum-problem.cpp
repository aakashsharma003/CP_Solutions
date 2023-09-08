//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	long long mod = 1e9 + 7;
	
	int solve(int indx,int *arr, int sum, vector<vector<int>>&dp){
	    
	    if(indx == 0){
        if(arr[0] == 0 && sum == 0)return 2;
        if(sum == 0 || arr[0] == sum)return 1;
          return 0;
	    }
	 
	    if(dp[indx][sum] != -1) return dp[indx][sum];
	    int take = 0;
	    if(arr[indx] <= sum)
	    take = solve(indx - 1, arr, sum - arr[indx], dp);
	    
	    int nottake = solve(indx - 1, arr, sum, dp);
	   
	    return dp[indx][sum] = (take + nottake) % mod;
	}

	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n, vector<int>(sum + 1, -1));
        return solve(n - 1, arr, sum, dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends