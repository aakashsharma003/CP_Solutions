//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // tabulation approach
    int minimizeCost(vector<int>& height, int n, int k) 
    {   vector<int>dp(n,-1);
        dp[0] = 0;
       int mini,enrgy;
        for(int j = 1;j<n;j++)
        {   mini = INT_MAX;
            for(int i =1;i<=k;i++)
          {
            if(j >=i)
            enrgy = dp[j-i]+abs(height[j]-height[j-i]);
            else
            enrgy = INT_MAX;
            mini = min(mini,enrgy);
           }
           dp[j] = mini;
        }
       return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends