// class Solution {
// public:
// int solve(int idx,vector<int>&nums,vector<int>&dp){ // memoizations::
//     if(idx>=nums.size()) return 0;
//     if(dp[idx]!=-1) return dp[idx];
//     // pick
//     int left = nums[idx]+solve(idx+2,nums,dp);
//     // none pick
//     int right = 0+ solve(idx+1,nums,dp);

//     return dp[idx]=max(left,right);  // same as adjacent sum :max
// }
//     int rob(vector<int>& nums) {
//         vector<int>dp(nums.size()+1,-1);
//         return solve(0,nums,dp);
//     }
// };

class Solution { // tebulations t.c= O(N) s.c= O(N) dp array
public:
int solve(int idx,vector<int>&nums,vector<int>&dp){

    dp[0]=nums[0];

    for(int i=1;i<nums.size();i++){
        int temp=0;
        if(i-2>=0) temp=dp[i-2];

        int take= nums[i]+ temp;
        int nontake= 0+ dp[i-1];

        dp[i]=max(take,nontake);
    }
    return dp[nums.size()-1]; // same as adjacent sum :max
}
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),0);
        return solve(0,nums,dp);
    }
};