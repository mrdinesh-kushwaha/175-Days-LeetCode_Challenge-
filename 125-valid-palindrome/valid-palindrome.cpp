class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int left=0;
        int right = n-1;

        //isalnum ->allowed 'a-z A-Z 0-9' only

        while(left<right){
            while(left<right && !isalnum(s[left])) left++;
            while(left<right && !isalnum(s[right])) right--;

            if(tolower(s[left])!=tolower(s[right]))
            return false; // means not palidrome
            left++;
            right--;
        }
        return true;
    }
};