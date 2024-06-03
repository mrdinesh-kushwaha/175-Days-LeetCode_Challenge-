// class Solution {
// public:
// int solve(vector<int>&coins,int amount){
//     if(amount==0) return 0;
//     if(amount<0) return INT_MAX;
//     int mini=INT_MAX;
//     for(int i=0;i<coins.size();i++){
//         int ans= solve(coins,amount-coins[i]);  // TLE
//         if(ans!=INT_MAX) 
//         mini= min(mini,1+ans);
//     }
//     return mini;
// }
//     int coinChange(vector<int>& coins, int amount) {
//     int ans= solve(coins,amount);
//     if(ans==INT_MAX) return -1;
//     else return ans;
//     }
// };

class Solution {  // memoizations
public:
int solve(vector<int>&coins,int amount,vector<int>&dp){
    if(amount==0) return 0;
    if(amount<0) return INT_MAX;
    if(dp[amount]!=-1) return dp[amount];
    int mini=INT_MAX;
    for(int i=0;i<coins.size();i++){
        int ans= solve(coins,amount-coins[i],dp);
        if(ans!=INT_MAX) 
        mini= min(mini,1+ans);
    }
    return dp[amount]=mini;
}
    int coinChange(vector<int>& coins, int amount) {
    vector<int>dp(amount+1,-1);
    int ans= solve(coins,amount,dp);
    if(ans==INT_MAX) return -1;
    else return ans;
    }
};