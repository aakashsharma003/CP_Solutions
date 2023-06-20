//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void printNeg(vector<int>&nums,int n){
        if(n == nums[0]){
            nums.push_back(n);
            return;
        }
        nums.push_back(n);
        printNeg(nums,n+5);
        return;
    }
    void printPos(vector<int>&nums,int n){
        if(n <= 0){
            nums.push_back(n);
            printNeg(nums,n+5);
            return;
        }
        nums.push_back(n);
        printPos(nums,n-5);
        return;
    }
    vector<int> pattern(int N){
        vector<int>ans;
        printPos(ans,N);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends