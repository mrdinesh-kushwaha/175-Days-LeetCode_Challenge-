class Solution {
public:
    int getLucky(string s, int k) {
        
        string temp="";
        for(int i=0;i<s.length();i++){
            int num=s[i]-'a'+1;
            temp+=to_string(num);
        }
        int ans=0;
        while(k){
           for(int i=0;i<temp.length();i++){
            ans+=temp[i]-'0';
           }
           k--;
           if(k!=0){
           temp=to_string(ans);
           ans=0;
           }
        }
        return ans;
    }
};