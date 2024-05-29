class Solution {
public:
void solve(int col,int n,vector<string>temp,vector<vector<string>>&ans,
vector<int>&leftRow,vector<int>&upperDiagonal,vector<int>&lowerDiagonal){
    //base case:::
    if(col==n){
        ans.push_back(temp);
        return;
    }

    for(int row=0;row<n;row++){
        if(leftRow[row]==0 && upperDiagonal[n-1+(col-row)]==0 && lowerDiagonal[col+row]==0){
            temp[row][col]='Q';
            //mark
            leftRow[row]=1;
            upperDiagonal[n-1+(col-row)]=1;
            lowerDiagonal[col+row]=1;
            solve(col+1,n,temp,ans,leftRow,upperDiagonal,lowerDiagonal); // call for next column::
            // now backtrack in original state :::
            temp[row][col]='.';
            leftRow[row]=0;
            upperDiagonal[n-1+(col-row)]=0;
            lowerDiagonal[col+row]=0;
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>>ans;
        vector<string>temp(n);
        string s(n,'.');
        for(int i=0;i<n;i++)temp[i]=s;
        // for checking leftRow, upperDiagonal and lowerDiagonal:::
        vector<int>leftRow(n,0),upperDiagonal(2*n-1,0),lowerDiagonal(2*n-1,0);

        solve(0,n,temp,ans,leftRow,upperDiagonal,lowerDiagonal);
        return ans;
    }
};