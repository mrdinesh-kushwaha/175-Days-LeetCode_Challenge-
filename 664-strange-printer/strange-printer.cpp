class Solution {
private:
    vector<vector<int>> dp;
public:
    int strangePrinter(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int n=s.size();
        dp.assign(n+1,vector<int>(n+1,0));
        for(int l=n-1; l>=0; l--){
            for(int r=l; r<n; r++){
                int res = 1+dp[l+1][r];
                for(int i=l+1;i<=r;i++){
                    if(s[l]==s[i]){
                        res = min(res,dp[l][i-1] + dp[i+1][r]);
                    }
                } 
                dp[l][r] = res;
            }
        }
        return dp[0][n-1];
    }
};