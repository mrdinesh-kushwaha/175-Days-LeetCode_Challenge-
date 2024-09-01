class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // vector<vector<int>>result(m,vector<int>(n));
        // //edages case::
        // int size=original.size();
        // if(m*n!=size) return {};

        // int p=0; // used for access original array element //T.C//O(m*n)
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //        result[i][j]=original[p++];
        //     }
        // }
        // return result;

        //M-2

        vector<vector<int>>result(m,vector<int>(n));
        int size=original.size();
        if(m*n!=size) return {};

        for(int i=0;i<size;i++){
            int row=i/n; // find row
            int col=i%n; // find col
            result[row][col]=original[i];
        }
        return result;
    }
};