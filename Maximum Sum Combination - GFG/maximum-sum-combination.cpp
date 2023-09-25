//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        vector<int>ans;
        priority_queue<pair<int,int>>minhp;
        
        for(int i =0;i < n;i++){
            int sum = a[i] + b[n-1];
            minhp.push({sum, n-1});
        }
        
        while(!minhp.empty() and k--){
            
            int sum = minhp.top().first;
            int indx = minhp.top().second;
            minhp.pop();
            ans.push_back(sum);
            if(indx - 1 >= 0)
            minhp.push({sum - b[indx] + b[indx - 1], indx - 1});
            
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends