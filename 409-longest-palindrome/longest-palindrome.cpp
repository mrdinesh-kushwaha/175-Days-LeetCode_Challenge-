class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]-'0']++;
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
        if(f==true)
        return 1+ ans;
        else
        return ans;
    }
};