class Solution {
public:
int m,n;
    void DFS(vector<vector<int>>&grid,int i,int j,vector<vector<bool>>& vis){
        //base case:
        if(i<0 ||i>=m ||j<0 ||j>=n ||vis[i][j]==true ||grid[i][j]==0){
            return ;
        }
        vis[i][j]=true; // marking
        DFS(grid,i-1,j,vis);
        DFS(grid,i+1,j,vis);
        DFS(grid,i,j-1,vis);
        DFS(grid,i,j+1,vis);
    }
    int numberOfIsland(vector<vector<int>>&grid){ // count no of island
        int isIsland=0;
        vector<vector<bool>>vis(m,vector<bool>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    DFS(grid,i,j,vis);
                    isIsland++;
                }
            }
        }
        return isIsland;
    }
    int minDays(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        int island=numberOfIsland(grid);
        if(island==0 || island >1) return 0;

        else{
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;//convert into water:

                    island=numberOfIsland(grid);
                    if(island==0 || island >1) return 1;

                    grid[i][j]=1; // again convert into land:
                }
            }
        }
    }
        return 2;
    }
};