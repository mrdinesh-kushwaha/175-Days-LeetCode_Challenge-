class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0; // Two pointers
        int n1 = str1.length(), n2 = str2.length();
        
        while (i < n1 && j < n2) {
            // Check if characters match directly or can match by incrementing
            if ((str2[j] - str1[i] + 26) % 26 <= 1) {
                j++; // Move to the next character in str2
            }
            i++; // Always move to the next character in str1
        }
        
        // If all characters in str2 are matched
        return j == n2;
    }
};