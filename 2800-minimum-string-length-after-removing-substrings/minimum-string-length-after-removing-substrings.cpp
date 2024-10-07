class Solution {
public:
    int minLength(string s) {
        
        int len = s.length();
        int i=0;
        while(i<len-1){
            if((s[i]-0== 65 && s[i+1]-0 == 66) || (s[i]-0== 67 && s[i+1]-0 == 68)){
                s.erase(i,2);
                i=0;
            }
            else i++;
        }
        return s.length();
    }
};