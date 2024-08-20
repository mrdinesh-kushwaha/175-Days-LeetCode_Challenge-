class Solution {
public:
    int n;
    int t[2][101][101];
    int solveForAlice(vector<int>&piles,int person,int idx,int M){

        if(idx>=n) return 0;

        int result=(person==1)? -1: INT_MAX; // for allice -1 bcz max, for bob INT_MAX ->min
        int stones=0;
        if(t[person][idx][M]!=-1) return t[person][idx][M];

        for(int x=1;x <= min(2*M,n-idx);x++){
            stones+=piles[idx+x-1];

            if(person==1) // for allice
            {
                result=max(result,stones+solveForAlice(piles,0,idx+x,max(M,x)));
            }
            else{ // for bob
                result=min(result, solveForAlice(piles,1,idx+x,max(M,x)));
            }
        }
    return t[person][idx][M]=result;

    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        memset(t,-1,sizeof(t));
        return solveForAlice(piles,1,0,1);
    }
};