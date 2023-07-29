#include<bits/stdc++.h>
using namespace std;
// time complexity->O(nlogn*t) , S.C->o(n)
 bool cmp(pair<int,int> &a,pair<int,int> &b){
    if(a.first != b.first) 
        return a.first > b.first;

    return a.second < b.second;
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i =0;i<n;i++)
	   cin>>arr[i];
	unordered_map<int,int>mp;
	for(int i =0;i<n;i++)
	  mp[arr[i]]++;
     
    vector<pair<int,int>>ans; 
    for(auto it:mp)
    ans.push_back({it.second,it.first});
    
    sort(ans.begin(),ans.end(),cmp);
    for(auto &it: ans){
    int freq = it.first;
    while(freq--)
    cout<<it.second<<" ";
    }
    cout<<endl;
	}
	
	return 0;
}