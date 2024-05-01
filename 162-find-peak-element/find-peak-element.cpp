class Solution {
public:
    // int findPeakElement(vector<int>& nums) {
    //     for(int i=1;i<nums.size();i++){
    //         int right=INT_MIN; // mark right which size ==nums.size() mark INT_MIN
    //         if(i<nums.size()-1){
    //             right=nums[i+1];
    //         }
    //         if(nums[i-1]<nums[i] && nums[i]>right){   // O(N) TIME:::
    //             return i;  
    //         }
    //     }
    //     return 0;
    // }

    //M-2*******************O(LOGN)********/////////////////////////
    int recursive_binary_search(vector<int>& nums, int low, int high){
        if(low == high){
            return low;
        }
        int mid = (low + high) >> 1;
        if(nums[mid] > nums[mid+1]){
            return recursive_binary_search(nums, low, mid);
        }
        else{
            return recursive_binary_search(nums, mid+1, high);
        }
    }
public:
    int findPeakElement(vector<int>& nums) {
        return recursive_binary_search(nums, 0, nums.size()-1);
    }
};