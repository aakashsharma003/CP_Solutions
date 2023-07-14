//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    {   
        unordered_map<int,int>mp;
        int mini = 1;
        for(int i =0;i<n;i++)
          mp[arr[i]]++;
        
        for(int j =0;j<n;j++)
        {
         if(arr[j] > 0)
         mini = min(mini,arr[j]);
        }
        
        for(int j =0;j<n;j++)
        {
          if(arr[j] > 0)
          {
              if(mp[mini] == 0)
              return mini;
              else
              mini++;
          }
        }
        return mini;
        // Your code here
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends