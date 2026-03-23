class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = nums[0]; //best ending
        int res = nums[0];

        for(int i=1;i<nums.size();i++){
            curr = max(nums[i],curr+nums[i]);
            res = max(res, curr);
        }
        return res;
    }
};