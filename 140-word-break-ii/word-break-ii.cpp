class Solution {
public:
void backtrack(string& s,unordered_set<string>&set,vector<string>&ans,int index,string curr){
    if(index==s.length()){
        ans.push_back(curr);
        return ;
    }
    string temp="";
    for(int i=index;i<s.length();i++){
        temp+=s[i];
        if(set.find(temp)!=set.end()){
            backtrack(s,set,ans,i+1,curr+temp+(i<s.length()-1? " ":""));
        }
    }
}
    vector<string> wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string>set(wordDict.begin(),wordDict.end());
        vector<string>ans;
        backtrack(s,set,ans,0,"");
        return ans;
    }
};