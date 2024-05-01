class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        // int firstOcc=0;

        // for(int i=0;i<word.length();i++){
        //     if(word[i]==ch){
        //         firstOcc=i+1;
        //         break;
        //     }
        // }
        // if(firstOcc!=0){
        // reverse(word.begin(),word.begin()+firstOcc);
        // return word;
        // }
        // else{
        //     return word;
        // }

        //**M-2 ***
        
        string ans="";

        bool check=true;

        for(auto& c:word){
            if(c==ch && check==true){
                ans+=c;
                reverse(ans.begin(),ans.end());
                check=false;
            }
            else{
                ans+=c;
            }
        }
        return ans;
    }
};