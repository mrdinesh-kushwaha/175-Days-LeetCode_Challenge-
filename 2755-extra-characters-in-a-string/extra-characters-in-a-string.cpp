class Solution {
public:
int minExtraChar(string s, vector<string>& dictionary) {
    unordered_set<string> st(dictionary.begin(), dictionary.end());
    int n = s.length();
    
    vector<int> dp(n + 1, n); //initialize with maxLen(n) of s
    dp[0] = 0;  // No extra characters if no characters are processed

    for (int i = 1; i <= n; i++) {
        // Case 1: Skip the current character
        dp[i] = dp[i - 1] + 1;
        
        // Case 2: Try to match dictionary words ending at position i-1
        for (int j = i; j > 0; j--) {
            string substring = s.substr(j - 1, i - j + 1);
            if (st.find(substring) != st.end()) {
                dp[i] = min(dp[i], dp[j - 1]);
            }
        }
    }

    return dp[n];
  }
};