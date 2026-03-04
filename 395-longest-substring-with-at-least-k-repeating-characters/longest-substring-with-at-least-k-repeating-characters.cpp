class Solution {
public:
    int longestSubstring(string s, int k) {
        //Using Recursion
        if(s.length()==0) return 0;

        int freq[26]={0};
        for(char ch:s) freq[ch-'a']++;

        for(int i=0;i<s.length();i++){
            //for Invalid case me
            if(freq[s[i]-'a'] < k){
                //then split left part and right part
                int left = longestSubstring(s.substr(0,i),k);
                int right = longestSubstring(s.substr(i+1),k);

                return max(left,right);
            }
        }
    // means all char correct freq >= k
    return s.length();
    }
};