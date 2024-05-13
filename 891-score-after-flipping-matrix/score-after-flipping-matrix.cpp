class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {

        //there are two case to solve this problem
        //case-1 : traverse each row if MSB is Zero then Toggle
        //case-2 : travesre in col if noZero > noOne the toggle:

        int row=grid.size();
        int col=grid[0].size();
        int score=0;

        //case:1 
        for(int i=0;i<row;i++){
            if(grid[i][0]==0){
                //toggle its means MSB is Zero::
                for(int j=0;j<col;j++){
                grid[i][j]= 1-grid[i][j];
                }
            }
        }

        // case-2:
        for(int j=1;j<col;j++){

            int countZero=0;
            for(int i=0;i<row;i++){
                if(grid[i][j]==0){
                    countZero++;
                }
            }

            int countOne= row-countZero;

            if(countZero > countOne){
                // that' s toggle:
                for(int i=0;i<row;i++){
                    grid[i][j]= 1-grid[i][j];
                }
            }

        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                score+=grid[i][j]*pow(2,col-j-1);
            }
        }
        return score;
    }
};