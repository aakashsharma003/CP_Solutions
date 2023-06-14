class Solution {
public:
    int lower_bound(vector<int>&arr,int target){
        int indx = -1;
        int low = 0,high = arr.size()-1,mid;
        while(low <= high){
              mid = low+(high-low)/2;
            if(target == arr[mid]){
                indx = mid;
                return indx;
            }
            else if(arr[mid] <= arr[high]){
                if(arr[mid] <= target && target <= arr[high])
                low = mid+1;
                else
                high = mid-1;
            }
            else if(arr[low] <= arr[mid]){
                if(arr[low] <= target && target <= arr[mid])
                high = mid-1;
                else
                low = mid+1;
            }
        }
        return indx;
    }
    
    int search(vector<int>& nums, int target) {
          int indx = lower_bound(nums,target);
          return indx;
    }
};