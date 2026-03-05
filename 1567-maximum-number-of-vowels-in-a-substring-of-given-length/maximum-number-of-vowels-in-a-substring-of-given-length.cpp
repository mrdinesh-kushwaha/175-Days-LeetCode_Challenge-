class Solution {
// public:
// int countVowels(string str,int left, int right){
//     int count=0;
//     for(int i=left;i<=right;i++){
//         if(str[i]=='a' || str[i]=='i' || str[i]=='e' || str[i]=='o' ||str[i]=='u')
//         count++;
//     }
//     return count;
// }
// public:
//     int maxVowels(string s, int k) {
//         if(s.length() < k) return 0;

//         int size = s.length();
//         int ans = 0;
//         int left=0;
    
//         for(int right = 0;right < size; right++){
//             if(right-left+1 == k){
//                 // count kro kitna vowels hai str me
//                 int count = countVowels(s,left,right);
//                 ans = max(ans,count);
//                 left++;
//             }
//         }
//         return ans;
//     }

    //Optimise Solution
    public:
    int maxVowels(string s, int k) {

        if(s.length() < k) return 0;

        int ans = 0;
        int countVowels = 0;
        int left=0;
        for(int right=0;right<s.length();right++){
            if(s[right]=='a' || s[right]=='i' ||s[right]=='o' ||s[right]=='e' ||s[right]=='u')
            countVowels++;

            if(right-left+1 == k){
                ans = max(ans,countVowels);
                
                if(s[left]=='a'||s[left]=='e'||s[left]=='i'||s[left]=='o'||s[left]=='u')
                countVowels--;

                left++;
            }
        }
        return ans;
    }
};