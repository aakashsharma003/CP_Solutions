//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {   
        int prev = arr[0];
        int prev2,curr_i,take,notTake;
        for(int i =1;i<n;i++){
            if(i > 1)
            take = arr[i] + prev2;
            else
            take = arr[i];
            
            notTake = 0 + prev;
            curr_i = max(take,notTake);
            prev2 = prev;
            prev = curr_i;
        }
        return prev;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends