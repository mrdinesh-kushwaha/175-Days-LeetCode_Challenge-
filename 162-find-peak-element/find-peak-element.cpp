class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            int right=INT_MIN;
            //int left=INT_MIN;
            if(i<nums.size()-1){
                right=nums[i+1];
            }
            if(nums[i-1]<nums[i] && nums[i]>right){
                return i;
            }
        }
        return 0;
    }
};