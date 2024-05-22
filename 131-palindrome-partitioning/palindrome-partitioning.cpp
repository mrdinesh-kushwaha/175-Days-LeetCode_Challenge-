class Solution {
public:
    bool isPalidrome(string& s,int l,int r){
        while(l<r){
            if(s[l]!=s[r])
            return false;
            l++;
            r--;
        }
        return true;
    }
    void backtrack(string &s, int idx,vector<string>curr,vector<vector<string>> &ans){
        // base case:
        if(idx==s.length()){
            ans.push_back(curr);
            return ;
        }
        for(int i=idx;i<s.length();i++){

            if(isPalidrome(s,idx,i)){

                curr.push_back(s.substr(idx,i-idx+1));
                backtrack(s,i+1,curr,ans); // call reursion
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>>ans;
        vector<string>curr;

        backtrack(s,0,curr,ans);

        return ans;
    }
};