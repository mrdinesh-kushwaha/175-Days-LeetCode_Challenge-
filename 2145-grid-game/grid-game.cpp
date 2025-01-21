class Solution {
public:
  long long gridGame(vector<vector<int>>& grid) {
    int n = grid[0].size();
    
    vector<long long> prefixTop(n + 1, 0);
    vector<long long> prefixBottom(n + 1, 0);
    
    for (int i = 0; i < n; ++i) {
        prefixTop[i + 1] = prefixTop[i] + grid[0][i];
        prefixBottom[i + 1] = prefixBottom[i] + grid[1][i];
    }
    
    long long result = LLONG_MAX;
    
    for (int i = 0; i < n; ++i) {
        long long topPath = prefixTop[n] - prefixTop[i + 1];
        long long bottomPath = prefixBottom[i];
        long long secondRobotPoints = max(topPath, bottomPath);
        result = min(result, secondRobotPoints);
    }
    
    return result;
   }
};