class Solution {
public:
    int t[100001][2][3];
int solve(int n,int ab,int late,int m){
    if(ab>1 || late>2) return 0;
    if(n==0) return 1;
    if(t[n][ab][late]!=-1) return t[n][ab][late];// Dp
    int a=solve(n-1,ab+1,0,m)%m;
    int p=solve(n-1,ab,0,m)%m;
    int l=solve(n-1,ab,late+1,m)%m;

    return t[n][ab][late]=((a+l)%m+p)%m;
}
    int checkRecord(int n) {
        int m=1e9+7;
        memset(t,-1,sizeof(t));
       int count=solve(n,0,0,m);
        return count;
    }
};