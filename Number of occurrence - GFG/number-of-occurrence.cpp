//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int first_occurance(int arr[],int n ,int x){
   int low = 0,high = n-1;
    int indx = n;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == x){
          indx = mid;
           high = mid -1;
        }
        else if(arr[mid] < x)
          low = mid +1;
        else
          high = mid - 1;
    }
    return indx;
   
}
int last_occurance(int arr[],int n ,int x){
   int low = 0,high = n-1;
    int indx = n;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == x){
          indx = mid;
           low = mid +1;
        }
        else if(arr[mid] < x)
          low = mid +1;
        else
          high = mid - 1;
    }
    return indx;
}
int count(int arr[], int n , int x )
{    
    pair<int,int>ans;
    ans.first = first_occurance(arr,n,x);
    
    if(ans.first == n)
    return 0;
    ans.second = last_occurance(arr,n,x);
    return {ans.second-ans.first+1};
    // code here
}
};  

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends