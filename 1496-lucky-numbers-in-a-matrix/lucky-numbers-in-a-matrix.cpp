class Solution {
public:
vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    vector<int> ans;
    int row = matrix.size();
    int col = matrix[0].size();

    // Find the minimum element in each row
    vector<int> rowMin(row, INT_MAX);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            rowMin[i] = min(rowMin[i], matrix[i][j]);
        }
    }

    // Find the maximum element in each column
    vector<int> colMax(col, INT_MIN);
    for (int j = 0; j < col; ++j) {
        for (int i = 0; i < row; ++i) {
            colMax[j] = max(colMax[j], matrix[i][j]);
        }
    }

    // Check for lucky numbers
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) {
                ans.push_back(matrix[i][j]);
            }
        }
    }

    return ans;
    }
};