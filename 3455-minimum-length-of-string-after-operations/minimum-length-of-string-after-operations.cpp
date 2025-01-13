class Solution {
public:
    int minimumLength(string s) {
        vector<int> cnt(26, 0);
        int len = 0;
        
        for (char ch : s) {
            cnt[ch - 'a']++;
        }
        
        for (int num : cnt) {
            if (num == 0) continue;
            len += (num % 2 == 0) ? 2 : 1;
        }        
        return len;
    }
};