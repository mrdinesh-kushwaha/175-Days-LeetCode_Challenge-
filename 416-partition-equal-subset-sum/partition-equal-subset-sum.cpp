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
bool getEqaulSubsetSum(vector<int>&nums,int target){ // space optimise tebulation (bootom-up)
    int n=nums.size();
    vector<vector<int>>dp(n+1,vector<int>(target+1,0));
    // when target(col) ->0 then val 1
    for(int idx=0;idx<n;idx++){
        dp[idx][0]=1;
    }

    for(int idx=n-1;idx>=0;idx--){
        for(int t=1;t<=target;t++){
        bool take=0;
        if(t-nums[idx]>=0) take= dp[idx+1][t-nums[idx]];
        bool nontake= dp[idx+1][t];

        dp[idx][t] = (take||nontake) ;
        }
    }
    return dp[0][target];
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto i:nums) sum+=i;
        if(sum & 1) return false;
        int target=sum/2;
        // vector<vector<int>>dp(n,vector<int>(target+1,-1));
        // return solve(0,nums,target,dp);

        return getEqaulSubsetSum(nums,target);
    }
};