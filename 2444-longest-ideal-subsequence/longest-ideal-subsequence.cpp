// class Solution {
// public:
    
// int longestIdealString(string s, int k) {
//     // int n = s.length();
//     // vector<int> dp(n, 1);
//     // int maxLen = 1;

//     // for (int i = 1; i < n; i++) {
//     //     for (int j = 0; j < i; j++) {
//     //         int diff = abs(s[i] - s[j]); ??Give TLE::::
//     //         if (diff <= k) {
//     //             dp[i] = max(dp[i], dp[j] + 1);
//     //             maxLen = max(maxLen, dp[i]);
//     //         }
//     //     }
//     // }

//     // return maxLen;
//     }
// };

class Solution {
public:
    int longestIdealString(string s, int k) {
        int dp[150] = {}, res = 0;
        for (auto& i : s) {
            for (int j = i - k; j <= i + k; ++j)
                dp[i] = max(dp[i], dp[j]);
            res = max(res, ++dp[i]);
        }
        return res;
    }
};