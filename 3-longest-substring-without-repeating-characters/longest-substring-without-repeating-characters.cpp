class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n=s.length();
        int maxLength=0;
        int left=0;
        unordered_set<char>st;
        for(int right=0;right<n;right++){
            while(st.find(s[right])!=st.end()){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            maxLength=max(maxLength,right-left+1);
        }
        return maxLength;
    }
};