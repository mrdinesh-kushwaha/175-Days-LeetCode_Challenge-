class Solution {
public:
    int minSwaps(string s) {
        
        int n= s.length();
        int ans=0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='['){
                ans++;
            }
            else if(ans>0){
                ans--;
            }
        }
        return (ans+1)/2;
    }
};