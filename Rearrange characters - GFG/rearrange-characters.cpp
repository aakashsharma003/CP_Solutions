//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
    public:
    string rearrangeString(string s)
    {
        int n = s.size();
        priority_queue<pair<int,char>>maxheap;
        unordered_map<char,int>mp;
        for(auto &it: s)
         mp[it]++;
         for(auto &it:mp){
            // cout<<it.first<<" "<<it.second<<endl;
         if(it.second > (n+1)/2) return "-1";
         maxheap.push({it.second,it.first});
         }
         string ans;
         pair<int,char>prev_freq = {-1,'$'};
         while(!maxheap.empty()){
            auto cur_freq = maxheap.top();
            maxheap.pop();
            ans.push_back(cur_freq.second);
          // cout<<prev_freq.first<<" "<<prev_freq.second<<endl;
            if(prev_freq.first > 0) {maxheap.push(prev_freq);}
            if(cur_freq.first > 0)
            prev_freq = {cur_freq.first - 1,cur_freq.second};
          
         }
        
       return ans;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}
// } Driver Code Ends