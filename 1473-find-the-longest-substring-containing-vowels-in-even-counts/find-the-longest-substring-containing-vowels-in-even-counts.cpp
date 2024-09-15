class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();

        int mask = 0, mxLen = 0;
        vector<int> seen(32, -1);  

        for(int i=0; i<n; i++)
        {
            if(s[i] == 'a') mask ^= (1 << 0);
            if(s[i] == 'e') mask ^= (1 << 1);
            if(s[i] == 'i') mask ^= (1 << 2);
            if(s[i] == 'o') mask ^= (1 << 3);
            if(s[i] == 'u') mask ^= (1 << 4);

            if(mask != 0 && seen[mask] == -1)   seen[mask] = i;

            mxLen = max(mxLen, i-seen[mask]);
        }

        return mxLen;
    }
};