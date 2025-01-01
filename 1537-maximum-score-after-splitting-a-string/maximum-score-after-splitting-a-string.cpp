class Solution {
public:
    int maxScore(string s) {
        int Total_Zeros=0;
        for(char c:s){
            if(c=='0')Total_Zeros++;
        }
        int ans=-1;
        int zeros=0;
        int L=s.length();
        for(int i=1;i<L;i++){
            if(s.at(i-1)=='0'){
                zeros++;
                Total_Zeros--;
            }
            ans=max(ans,(zeros+(L-Total_Zeros-(i))));
        }
        return ans;
        
    }
};