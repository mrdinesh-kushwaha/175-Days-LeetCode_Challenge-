class Solution {
public:
    //DFS
    bool checkIslands(vector<vector<int>>& grid1,vector<vector<int>>&grid2,int i,int j){
        //base case:
        if(i<0||i>=grid2.size()||j<0||j>=grid2[0].size()||grid2[i][j]!=1){
            return true;
        }
        if(grid1[i][j]!=1) return false;

        grid2[i][j]=-1; // mark visited

        bool up=checkIslands(grid1,grid2,i+1,j);
        bool down=checkIslands(grid1,grid2,i-1,j);
        bool right=checkIslands(grid1,grid2,i,j+1);
        bool left=checkIslands(grid1,grid2,i,j-1);

        return up && down && right && left;

    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        // traverse at grid2 beacuse mention in question 
        int row=grid2.size();
        int col= grid2[0].size();
        int noIslands=0;

        for(int i=0;i<row;i++){

            for(int j=0;j<col;j++){
                if(grid2[i][j]==1 && checkIslands(grid1,grid2,i,j)){
                    noIslands++;
                }
            }
        }
        return noIslands;
    }
};