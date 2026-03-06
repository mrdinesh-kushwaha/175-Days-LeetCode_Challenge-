class Solution {
// public:
// bool check(string s, string p, int left, int right){
//     int freq[26]={0};
//     for(char ch:p) freq[ch-'a']++;

//     for(int i=left;i<=right;i++){
//         freq[s[i]-'a']--;
//     }
//     //check freq
//     for(int i=0;i<26;i++) 
//     {
//         if(freq[i]!=0) return false;
//     }
//     return true;
// }
// public:
//     vector<int> findAnagrams(string s, string p) {
//         if(s.length() < p.length()) return {};

//         int left=0;
//         vector<int>ans;

//         for(int right=0;right<s.length();right++){

//             if(right-left+1 == p.length()){
//                 bool checkAnagram = check(s,p,left,right);
//                 if(checkAnagram==true)
//                 ans.push_back(left);

//                 left++;
//             }
//         }
//         return ans;
//     }

public:
    vector<int> findAnagrams(string s, string p) {
        //Using sliding window technique
        vector<int>ans;
        if(s.length() < p.length()) return ans;

        int fp[26]={0};
        for(char ch:p) fp[ch-'a']++; //stroring freq of p
        int fs[26]={0};
        int left=0; 
        int k = p.length();//window size

        for(int right=0;right<s.length();right++){
            fs[s[right]-'a']++; // add freq 
            if(right-left+1 == k){
                bool same=true; //for both fp, fs freq ke liye
                for(int i=0;i<26;i++){
                    if(fs[i]!=fp[i]) same = false;
                }
                if(same) ans.push_back(left); // if both freq eqaul then must be anagram

                fs[s[left]-'a']--; // remove s freq from left side
                left++;
            }
        }
        return ans;
    }
};