class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        int maxiLength = INT_MIN;
        int size = s.length();
        int left=0;
        unordered_set<char>st;

        for(int right=0;right<size;right++){
            while(st.find(s[right])!=st.end()){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            maxiLength = max(maxiLength, right-left+1);
        }
        return maxiLength;
    }
};