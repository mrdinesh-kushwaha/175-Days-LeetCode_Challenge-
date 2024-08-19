class Solution {
public:
    int solve(int currA,int clipA,int n,vector<vector<int>>& dp){
        if(currA==n) return 0;

        if(currA > n) return 100000;
        if(dp[currA][clipA]!=-1) return dp[currA][clipA];
        int copyAllPaste = 1+1+solve(currA+currA,currA,n,dp);
        int paste= 1+ solve(currA+clipA,clipA,n,dp);

        return dp[currA][clipA]=min(copyAllPaste,paste);
    }

    int minSteps(int n) {
        if(n==1) return 0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1)); // recursion+DP
        return 1+ solve(1,1,n,dp);
    }
};