class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // first take exta space O(N^2) and Not in-place solution
        // int n = matrix[0].size(); // col length both row and col length same:
        // vector<vector<int>>res(n,vector<int>(n));
        // int i=0;
        // for(int col=0;col<n;col++){
        //     int j=0;
        //     for(int row=n-1;row>=0;row--){
        //         int ele=matrix[row][col];
        //         res[i][j++]=ele;
        //     }
        //     i++;
        // }
        // matrix=res; // Copy res 2D array into matrix array 

        // Now, Optimise this solution (in-place)->means not take any Extra Space:

        // solved by Two Steps
        //step-1 Find Transpose(row<->col)
        //step-2 reverse each row

        int row = matrix.size();
        int col = matrix[0].size();
        //Step-1
        for(int i=0;i<row;i++){
            for(int j=i;j<col;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // Step-2
        for(int i=0;i<row;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};