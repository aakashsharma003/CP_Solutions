class Solution {
public:
    int arrayMax(vector<int>&arr){
        int maxi = INT_MIN;
        for(int i =0;i < arr.size();i++)
            maxi = max(arr[i],maxi);
     return maxi;
    }
    int arrayMin(vector<int>&arr){
        int mini = INT_MAX;
        for(int i =0;i < arr.size();i++)
            mini = min(arr[i],mini);
     return mini;
    }
    int countElements(vector<int>& nums) {
        int n = nums.size();
        int maxi = arrayMax(nums);
        int mini = arrayMin(nums);
        int cnt =0;
        for(int i =0;i<=n-1;i++){
            if(nums[i] != mini && nums[i] != maxi)
                cnt++;
        }
        return cnt;
    }
};