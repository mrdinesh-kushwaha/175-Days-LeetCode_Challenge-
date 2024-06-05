class Solution {
public:
    int solve(int n, int k, int target, int& mod, vector<vector<int>>& dp) {
        // base case:
        if (n < 0) // DP Memoization
            return 0;
        if (n == 0 && target == 0)
            return 1;
        if (n != 0 && target == 0)
            return 0;
        if (n == 0 && target != 0)
            return 0;
        if (dp[n][target] != -1)
            return dp[n][target];
        int ans = 0;
        for (int i = 1; i <= k; i++) {
            int recAns = 0;
            if (target - i >= 0)
                recAns = solve(n - 1, k, target - i, mod, dp);
            ans = (ans % mod + recAns % mod) % mod;
        }
        return dp[n][target] = ans;
    }
    int solveMem(int n, int k, int target, int& mod, vector<vector<int>>& dp) {
        // base case:
        if (n < 0)
            return 0;
        if (n == 0 && target == 0)
            return 1;
        if (n != 0 && target == 0)
            return 0;
        if (n == 0 && target != 0)
            return 0;
        if (dp[n][target] != -1)
            return dp[n][target];
        int ans = 0;
        for (int i = 1; i <= k; i++) {
            int recAns = 0;
            if (target - i >= 0)
                recAns = solve(n - 1, k, target - i, mod, dp);
            ans = (ans % mod + recAns % mod) % mod;
        }
        return dp[n][target] = ans;
    }
    int solveTab(int n, int k, int target, int& mod) {

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;

        for (int idx = 1; idx <= n; idx++) {
            for (int t = 1; t <= target; t++) {
                int ans = 0;
                for (int i = 1; i <= k; i++) {
                    int recAns = 0;
                    if (t - i >= 0)
                        recAns = dp[idx - 1][t - i];
                    ans = (ans % mod + recAns % mod) % mod;
                }
                dp[idx][t] = ans;
            }
        }
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        // return solve(n, k, target, mod, dp);

        return solveTab(n, k, target, mod);
    }
};