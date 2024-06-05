class Solution {
public:
int solve(int n,int k,int target,int &mod,vector<vector<int>>&dp){
    //base case:
    if(n<0)return 0;
    if(n==0&&target==0)return 1;
    if(n!=0 && target ==0) return 0;
    if(n==0 && target!=0) return 0;
    if(dp[n][target]!=-1) return dp[n][target];
    int ans=0;
    for(int i=1;i<=k;i++){
        int recAns=0;
        if(target-i>=0)
        recAns=solve(n-1,k,target-i,mod,dp);
        ans=(ans%mod+recAns%mod)%mod;
    }
    return dp[n][target] = ans;
}
    int numRollsToTarget(int n, int k, int target) {
        int mod=1e9+7;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(n,k,target,mod,dp);   
    }
};