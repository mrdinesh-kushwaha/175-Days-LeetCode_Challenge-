class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        
        int n=sentence.length();
        int i=0;
        int count=0;
        string str="";
        while(i<n){
            str+=sentence[i];
            if(str==searchWord){ // if find searchWord
                return count+1;
            }
            if(sentence[i]== ' '){ // if get new Word in Sentence:
                str="";
                count++;
            }
            i++;
        }
        return -1; // if not exist searchWord
    }
};