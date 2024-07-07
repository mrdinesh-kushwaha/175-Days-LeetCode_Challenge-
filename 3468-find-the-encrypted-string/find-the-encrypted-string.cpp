class Solution {
public:
    string getEncryptedString(string s, int k) {
        
        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++){
            // int t=k;
            // int j=i;
            // while(t--){
            //     if(j==n-1) j=0;
            //     else j++;
            // }
            // ans+=s[j];
            ans+=s[(k+i)%n];
        }
        return ans;
    }
};