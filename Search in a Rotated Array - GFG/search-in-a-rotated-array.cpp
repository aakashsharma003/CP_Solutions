//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int ans =-1;
    int search(int a[], int l, int h, int x){
        int mid = l+ (h-l)/2;
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        if(l > h)
        return ans;
        
        
        if(a[mid] == x)  return mid;
        
        else if(a[l] <= a[mid]){
            if(x >= a[l] && x <= a[mid])
             ans = search(a,l,mid-1,x);
             else{
              ans = search(a,mid+1,h,x);
             }
        }
        else{
            if(x >= a[mid] && x <= a[h])
             ans = search(a,mid+1,h,x);
             else{
             ans = search(a,l,mid-1,x);
             }
        }
        return ans;
        //complete the function here
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends