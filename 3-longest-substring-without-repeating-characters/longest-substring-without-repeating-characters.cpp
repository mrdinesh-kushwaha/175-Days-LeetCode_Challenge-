class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
       int n = s.length();
       unordered_set<char>st;
       int low=0;
       int high=0;
       int ans = INT_MIN;

       while(high<n){
            while(st.count(s[high])){
                st.erase(s[low]);
                low++;
            }
            st.insert(s[high]);
            ans=max(ans, high-low+1);
            high++;
       } 
       return ans;
    }
};