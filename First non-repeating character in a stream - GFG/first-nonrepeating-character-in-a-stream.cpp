//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		    // Code here
		    queue<char>q;
		    int arr[26] = {0};
		    string ans;

		    for( auto &ch : s )
		    {
		       arr[ch - 'a']++;
		       q.push(ch);
		       while(!q.empty()){
		          if(arr[q.front() - 'a'] == 1){
		              ans.push_back(q.front());
		              break;
		          }
		          else
		             q.pop();
		       }
		      if(q.empty())
		         ans.push_back('#');
		        
		    }
		    return ans;
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends