class Solution {
public:
bool isvalid(vector<vector<char>>& board,int row,int col,char ch){
    for(int i=0;i<9;i++){
        if(board[i][col]==ch) return false; // in row check occurence
        if(board[row][i]==ch) return false; // in column 
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==ch) return false; // in 3*3 grid occurence
    }
    return true;
}
bool solve(vector<vector<char>>& board){
    int row=board.size();
    int col=board[0].size();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(board[i][j]=='.'){ // if empty then 
                for(char ch='1';ch<='9';ch++){ // put 1 to 9 number and check valid sudoku or not
                    if(isvalid(board,i,j,ch)){ // putting 1-9 digit valid or not
                        board[i][j]=ch;// valid then fill into sudoku
                        if(solve(board)==true) return true; // again call if any more empty cells
                        else
                        board[i][j]='.'; // backtack not possible:
                    }
                }
                return false;
            }
        }
    }
    return true; // valid sudoku 
}
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};