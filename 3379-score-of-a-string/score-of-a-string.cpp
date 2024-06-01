class Solution {
public:
    int scoreOfString(string s) {
        int n=s.length();
        int i=0,j=1;
        int sum=0;
        while(j<n){
            int a=s[i]-'0';
            int b=s[j]-'0';
            sum+=abs(a-b);
            i++,j++;
        }
        return sum;
    }
};