class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        int ans=0;
        bool f=false;
        for(auto i: mp){
            int val= i.second;
            if(val&1==1) // means odd
            {   f=true;
                ans+=val-1;
            }
            else{
                ans+=val;
            }
        }
        if(f==true)  // means you have #odd then do otherwise return only ans:::
        return 1+ ans; // '+1' bzc in any palidrome we can insert one char in between :: eg. abbcbba
        else
        return ans;
    }
};