//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  // Space optomisation  T.C->O(N) S.C->O(1)
    int subsetSum(int arr[],int n,int k){
        
       vector<bool> prev(k+1,0),curr(k+1,0);
       prev[0] = curr[0] = true;
  
        for(int i =0;i< n;i++)
        prev[0] = true;

        if(arr[0] <= k )  prev[arr[0]] = true;

        for(int indx = 1;indx < n;++indx)
       {
           for(int target = 1;target <= k;++target)
          {
          
          bool notTake = prev[target];

          bool take = false;

           if(arr[indx] <= target)
           take = prev[target-arr[indx]];

           curr[target] = take | notTake;
          }
         prev = curr;
        
       }
 
       
       int mini = 1e9;
       for(int s1 =0;s1 <=k/2;s1++){
           
           if(prev[s1]){
           int s2 = k - s1;
           mini = min(mini,abs(s2-s1));
           }
           
       }
       
        return mini;
    }
  
  
  
  
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int totalSum =0;
	    for(int i = 0;i<n;i++) totalSum += arr[i];
	    return subsetSum(arr,n,totalSum);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends