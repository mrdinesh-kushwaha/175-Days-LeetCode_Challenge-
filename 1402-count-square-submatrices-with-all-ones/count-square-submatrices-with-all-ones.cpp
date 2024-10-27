class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();

        for (int i = 1; i < rowSize; i++) {
            for (int j = 1; j < colSize; j++) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] += min(matrix[i - 1][j], 
                                        min(matrix[i][j - 1], matrix[i - 1][j - 1]));
                }
            }
        }

        int total = 0;
        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                total += matrix[i][j];
            }
        }

        return total;
    }
};