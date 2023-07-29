//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

bool cmp(pair<int,int>&a,pair<int,int>&b){
    //freq agar same nhi h toh decending order mtlb a phle ayega then b
    if(a.first != b.first) 
    return a.first > b.first;
    
    //else dono brabr hogi freq so dono k second ka order accending m chahiye 
    return a.second < b.second;
}

class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(int arr[],int n)
    {
       vector<int>ans;
       unordered_map<int,int>mp;
	   for(int i = 0;i<n;i++)
	       mp[arr[i]]++;
        
       vector<pair<int,int>>temp; 
       for(auto it:mp)
       temp.push_back({it.second,it.first});
    
       sort(temp.begin(),temp.end(),cmp);
       for(auto &it: temp){
       int freq = it.first;
       while(freq--)
         ans.push_back(it.second);
       }     
      return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}


// } Driver Code Ends