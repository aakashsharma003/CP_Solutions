//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    //  space optomization approach TC-> O(n) ,SC->O(1)
    long long countWays(int n)
    {   long long prev = 1,prev2 =0,prev3 =0; 
        for(int i =1;i<=n;i++){
         long long step1 = prev;
         long long step2 = prev2;
         long long step3 = prev3;
         long long curr_i = (step1+step2+step3)%(1000000000+7);
         prev3 = prev2;
         prev2 = prev;
         prev = curr_i;
        }
        return prev;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends