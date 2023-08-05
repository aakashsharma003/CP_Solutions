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


string firstRepChar(string s)
{
    string ans = "-1";
    bool visited[26] = {false};
    for(int i=0;i<s.size();i++){
        if(visited[s[i]- 'a']){
            ans.pop_back();
            ans.pop_back();
            ans.push_back(s[i]);
            return ans;
        }    
        else
        visited[s[i]-'a'] = true;
    }
    return ans;
}