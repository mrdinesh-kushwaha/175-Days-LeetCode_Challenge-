class Solution {
public:
int solve(int idx,vector<int>&nums,vector<int>&dp){
    if(idx>=nums.size()) return 0;
    if(dp[idx]!=-1) return dp[idx];
    // pick
    int left = nums[idx]+solve(idx+2,nums,dp);
    // none pick
    int right = 0+ solve(idx+1,nums,dp);

    return dp[idx]=max(left,right);
}
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return solve(0,nums,dp);
    }
};