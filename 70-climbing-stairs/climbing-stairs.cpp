class Solution {
public:
int solve(int n,vector<int>&dp){
    if(n<0) return 0;
    if(n==0||n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=solve(n-1,dp)+solve(n-2,dp);
}
    int climbStairs(int n) {
    //     if(n<0)
    //     return 0;
    //     if(n==1)
    //     return 1;

    //     int n1=1;
    //     int n2=1;
    //     int sum=0;
        
    //    for(int i=2;i<=n;i++)
    //    {
    //     sum=n1+n2;
    //     n1=n2;
    //     n2=sum;
    //    }
    // return sum; 
    vector<int>dp(n+1,-1);
    return solve(n,dp);     
    }
};