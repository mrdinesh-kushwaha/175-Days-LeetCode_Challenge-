class Solution {
public:
    // Recursive function to find the minimum falling path sum
    int solve(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        // base case 
        if (r < 0 or r >= n or c < 0 or c >= m) return INT_MAX;

        // If at the bottom row, return the value at this position
        if (r == n - 1) return grid[r][c];

        // If the value at this position has been calculated before, return it
        if (dp[r][c] != -1) return dp[r][c];

        int sum = grid[r][c];
        int p = INT_MAX;
        // Iterate over all columns in the next row to find the minimum value
        for (int j = 0; j < m; j++) {
            if (j != c) {
                int temp = solve(r + 1, j, grid, dp);
                p = min(p, temp);
            }
        }
        sum += p; // Add the minimum value from the next row to the current sum
        return dp[r][c] = sum; // Memoize and return the result
    }
    
    // Main function to find the minimum falling path sum
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
       
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m, -1)); // Initialize DP table with -1

        // Iterate over all columns in the first row to start the falling path
        for (int i = 0; i < m; i++) {
            ans = min(ans, solve(0, i, grid, dp)); // Update answer with minimum falling path sum starting from each column
        }
        return ans; // Return the minimum falling path sum
    }
};