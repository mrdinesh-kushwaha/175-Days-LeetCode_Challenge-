class Solution {
public:
 int minSteps(int n) {
    vector<int> dp(n + 1, INT_MAX); // dp[i] will hold the minimum steps to get i 'A's
    dp[1] = 0; // No operations needed for 1 'A'

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            if (i % j == 0) {
                dp[i] = min(dp[i], dp[j] + (i / j)); // j 'A's pasted (i/j) times
                dp[i] = min(dp[i], dp[i / j] + j); // (i/j) 'A's pasted j times
            }
        }
    }
    return dp[n];
    }
};