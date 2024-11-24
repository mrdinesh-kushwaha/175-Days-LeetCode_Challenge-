class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int countNegatives = 0;
        int minAbsValue = INT_MAX;
        long long totalSum = 0;

        // Calculate total sum, count negatives, and find min absolute value
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                totalSum += abs(matrix[i][j]);
                if (matrix[i][j] < 0) {
                    countNegatives++;
                }
                minAbsValue = min(minAbsValue, abs(matrix[i][j]));
            }
        }

        // If the count of negatives is even, we can maximize the sum fully
        // If odd, we will have one negative left
        if (countNegatives % 2 == 0) {
            return totalSum; // Maximum sum is the sum of absolute values
        } else {
            // We need to subtract twice the smallest absolute value
            return totalSum - 2 * minAbsValue;
        }
    }
};