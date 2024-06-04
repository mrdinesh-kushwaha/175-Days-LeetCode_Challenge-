// class Solution {
// public:
// int solve(vector<int>&coins,int amount){  // USing Recursion:::: T.C=O(3^n*N) , S.C= O(3^n)
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

// class Solution {  // memoizations  T.C= O(N) S.C= O(N) dp array +O(N) stack call
// public:
// int solve(vector<int>&coins,int amount,vector<int>&dp){
//     if(amount==0) return 0;
//     if(amount<0) return INT_MAX;
//     if(dp[amount]!=-1) return dp[amount];
//     int mini=INT_MAX;
//     for(int i=0;i<coins.size();i++){
//         int ans= solve(coins,amount-coins[i],dp);
//         if(ans!=INT_MAX) 
//         mini= min(mini,1+ans); //+1 bcz not consider first element that's why
//     }
//     return dp[amount]=mini;
// }
//     int coinChange(vector<int>& coins, int amount) {
//     vector<int>dp(amount+1,-1);
//     int ans= solve(coins,amount,dp);
//     if(ans==INT_MAX) return -1;
//     else return ans;
//     }
// };

class Solution {  // tebulations  T.C= O(N) S.C= O(N) dp array
public:
int solve(vector<int>&coins,int amount,vector<int>&dp){
    dp[0]=0;

    for(int target=1;target<=amount;target++){
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(target-coins[i]>=0){
            int ans= dp[target-coins[i]];
            if(ans!=INT_MAX) mini=min(mini,1+ans);
        }
      }
      dp[target]=mini;
    }
    return dp[amount];
}
    int coinChange(vector<int>& coins, int amount) {
    vector<int>dp(amount+1,INT_MAX);
    int ans= solve(coins,amount,dp);
    if(ans==INT_MAX) return -1;
    else return ans;
    }
};