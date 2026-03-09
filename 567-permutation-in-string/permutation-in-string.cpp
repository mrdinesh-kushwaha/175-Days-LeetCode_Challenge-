class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int>freq1(26,0),freq2(26,0);
        for(char ch:s1) freq1[ch-'a']++;
        int left=0;
        int k = s1.size(); // windows size

        for(int right=0;right<s2.size();right++){
            freq2[s2[right]-'a']++;

            if(right - left + 1 > k){
                freq2[s2[left]-'a']--;
                left++;
            }
            if(freq1 == freq2) return true;
        }
        return false;
    }
};