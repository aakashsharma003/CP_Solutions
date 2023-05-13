//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &nums , int n){
        // code here 
         int l =0, r = k-1;
         long sum = 0; 
        for(int i =l;i<=r;i++)
            sum += nums[i];
        long ans = sum;
        while(l < n-k){  
            sum = sum-nums[l]+nums[r+1];   
            ans = max(ans,sum);
            l++;
            r++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends