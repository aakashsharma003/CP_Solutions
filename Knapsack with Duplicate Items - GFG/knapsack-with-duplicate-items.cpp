//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int knapSack(int n, int maxweight, int val[], int wt[])
    {
       vector<int> prev(maxweight+1,0),cur(maxweight+1,0);
        for(int w = 1;w<=maxweight;w++){
            prev[w] = val[0]*(w / wt[0]);
        }
          
        for(int indx = 1;indx<n;indx++){
            for(int w = 1;w <= maxweight;w++){
                
             int notpick = prev[w];
             int pick = 0;
             if(wt[indx] <= w)
             pick = val[indx] + cur[w-wt[indx]];
             cur[w] = max(pick,notpick);
            }
            prev = cur;
        }
        return prev[maxweight];
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