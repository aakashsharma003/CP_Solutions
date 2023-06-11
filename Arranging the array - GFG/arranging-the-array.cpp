//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
        void Rearrange(int arr[], int n)
        {   vector<int>ans;
            for(int i =0;i<n;i++)
            ans.push_back(arr[i]);
            
            int res = 0;
            for(int i =0;i<n;i++){
                if(ans[i] < 0){
                arr[res] = ans[i];
                res++;
                }
            }
            for(int i =0;i<n;i++){
                if(ans[i] >= 0){
                arr[res] = ans[i];
                res++;
                }
            }
            
           
           return;
            // Your code goes here
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends