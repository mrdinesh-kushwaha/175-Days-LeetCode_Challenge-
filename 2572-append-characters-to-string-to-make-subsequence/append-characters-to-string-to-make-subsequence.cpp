class Solution {
public:
    int appendCharacters(string s, string t) {
        
        int ans= t.length();
        int i=0;
        int j=ans;
        int k=0;
        while(k<j && i<s.length()){
            if(s[i]==t[k]){
                ans--;
                i++; k++;
            }
            else
            i++;
        }
        return ans;
    }
};