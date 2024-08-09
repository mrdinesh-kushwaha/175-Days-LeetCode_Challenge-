class Solution {
public:
bool ismagicalGrid(vector<vector<int>>& grid, int r, int c){
    //check uniqueness and 1-9
    unordered_set<int>st;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int num=grid[r+i][c+j];
            if(num<1 || num>9 || st.count(num)){
                return false;
            }
            else
            st.insert(num);
        }
    }
    int Sum= grid[r][c]+grid[r][c+1]+grid[r][c+2];
    // rowSum And colSum
    for(int i=0;i<3;i++){
        if((grid[r+i][c]+grid[r+i][c+1]+grid[r+i][c+2])!=Sum) return false; //rowSum

        if((grid[r][c+i]+grid[r+1][c+i]+grid[r+2][c+i])!=Sum) return false; //rowSum
    }

    // Diagonal Sum And Antidiagonal Sum
    if((grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2])!=Sum) return false; // Diagonal Sum

    if((grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c])!=Sum) return false; // antidiagonal Sum

    return true;
}
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        int count=0;
        for(int i=0;i<=rows-3;i++){
            for(int j=0;j<=cols-3;j++){
                if(ismagicalGrid(grid,i,j)){
                    count++;
                }
            }
        }
        return count;
    }
};