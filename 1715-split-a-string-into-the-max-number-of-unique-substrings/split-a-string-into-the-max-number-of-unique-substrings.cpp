class Solution {
public:
    void solve(string& s,int idx,unordered_set<string>&st,int& maxCount,int currCount){

        if(idx >= s.length()){ // BASE CASE:
            maxCount=max(maxCount,currCount);
            return;
        }
        for(int j=idx;j<s.length();j++){
            string sub=s.substr(idx,j-idx+1); // O(N)
            if(st.find(sub)==st.end()){
                st.insert(sub);
                solve(s,j+1,st,maxCount,currCount+1); // call recursion
                st.erase(sub); // use backtrack(UNDO)
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string>st;
        int maxCount=0;
        int currCount=0;
        int idx=0;
        solve(s,idx,st,maxCount,currCount);
        return maxCount;
    }
};