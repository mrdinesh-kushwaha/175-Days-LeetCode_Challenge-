class Solution {
public:
    static int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Initialize the last column to 1
        for (int i = 0; i < n; i++)
            dp[i][m - 1] = 1;

        // Process from the second last column to the 0th
        for (int j = m - 2; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                int x = grid[i][j];

                // Check the cell E
                int max_move = (x < grid[i][j + 1]) * dp[i][j + 1];

                // Check the cell NE
                if (i > 0 && x < grid[i - 1][j + 1])
                    max_move = max(max_move, dp[i - 1][j + 1]);

                // Check the cell SE
                if (i < n - 1 && x < grid[i + 1][j + 1])
                    max_move = max(max_move, dp[i + 1][j + 1]);

                dp[i][j] = 1 + max_move;
            }
        }

        // Calculate the maximum moves
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, dp[i][0]);

        return ans - 1; // subtracting 1 as per initial setup
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();