//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends

// T.C(N) S.C->O(1)
string firstRepChar(string s)
{
    string ans = "-1";
    // agar direct index ki jgh character use krne h toh 128 ka array lo 
    bool visited[128] = {false};
    for(int i=0;i<s.size();i++){
        if(visited[s[i]]){
            ans.pop_back();
            ans.pop_back();
            ans.push_back(s[i]);
            return ans;
        }    
        else
        visited[s[i]] = true;
    }
    return ans;
}