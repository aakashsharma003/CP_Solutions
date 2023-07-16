class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),m = nums2.size();
//         int left = n-1, right = 0;
//            while(left >= 0 && right < m){
//             if(nums1[left] > nums2[right]){
//                 swap(nums1[left],nums2[right]);
//                 left--;
//                 right++;
//             }
//             else
//                break;        
//             }
         
//          sort(nums1.begin(),nums1.end());
//          sort(nums2.begin(),nums2.end());
        vector<int>ans(n+m);
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),ans.begin());
        sort(ans.begin(),ans.end());
        // for(auto &c:ans)
        // cout<<c<<" ";    
        double res = 0;
        int mid = (n+m-1)/2;
        if((n+m)%2 == 1)
         res = ans[mid];
        else
          res = (ans[mid] + ans[mid+1])/2.0;
        
        return res;
    }
};