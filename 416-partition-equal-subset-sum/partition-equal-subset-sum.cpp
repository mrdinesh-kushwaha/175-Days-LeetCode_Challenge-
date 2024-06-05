class Solution {
public:
bool solve(int idx,vector<int>&nums,int target,vector<vector<int>>&dp){

        //base case:
        if(idx>=nums.size()) return false;
        if(target<0)return false;
        if(target==0)return true;
        
        if(dp[idx][target]!=-1) return dp[idx][target];

        bool take= solve(idx+1,nums,target-nums[idx],dp);
        bool nontake= solve(idx+1,nums,target,dp);

        dp[idx][target] = (take||nontake) ;
        return dp[idx][target];

}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto i:nums) sum+=i;
        if(sum & 1) return false;
        int target=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(0,nums,target,dp);
    }
};