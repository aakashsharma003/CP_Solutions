class Solution {
public: 
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = 0,cnt = 0;
        while(nums[i] != 1)
            i++;
        
        while(i > 0){
            swap(nums[i],nums[i-1]);
            cnt++;
            i--;
        }
        
        int j = 0;
        while(nums[j] != n)
            j++;
        
        while(j < n-1){
            swap(nums[j],nums[j+1]);
            j++;
            cnt++;
        }
       return cnt; 
    }
};