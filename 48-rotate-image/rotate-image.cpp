class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // first take exta space 
        int n = matrix[0].size(); // col length both row and col length same:
        vector<vector<int>>res(n,vector<int>(n));
        int i=0;
        for(int col=0;col<n;col++){
            int j=0;
            for(int row=n-1;row>=0;row--){
                int ele=matrix[row][col];
                res[i][j++]=ele;
            }
            i++;
        }
        matrix=res;
    }
};