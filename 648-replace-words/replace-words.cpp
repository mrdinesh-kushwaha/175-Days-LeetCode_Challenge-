class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {

        unordered_set<string>st(dictionary.begin(),dictionary.end());
        string ans="";
        int i=0;
        while(i<sentence.size()){
            string temp="";
            bool match=false;
            while(i<sentence.size() && sentence[i]!=' '){
                if(match==true){
                    i++;
                    continue;
                }
                temp+=sentence[i++];
                if(st.find(temp)!=st.end()){ //then not update temp:
                    match=true;
                }
            }
            ans+=temp;
            if(i<sentence.size() && sentence[i]==' ') // add ans space " "
            ans+=" ";

            i++;
        }
        return ans;
    }
};