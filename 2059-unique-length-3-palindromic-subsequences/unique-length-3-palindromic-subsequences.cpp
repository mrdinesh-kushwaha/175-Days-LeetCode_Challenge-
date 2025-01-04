class Solution {
public:
    int countPalindromicSubsequence(string s) {
           int n = s.size();
    vector<int> firstPos(26, -1), lastPos(26, -1);
    unordered_set<string> uniquePalindromes;

    // Record the first and last occurrence of each character
    for (int i = 0; i < n; i++) {
        if (firstPos[s[i] - 'a'] == -1) {
            firstPos[s[i] - 'a'] = i;
        }
        lastPos[s[i] - 'a'] = i;
    }

    // Check for palindromes
    for (char c = 'a'; c <= 'z'; c++) {
        int start = firstPos[c - 'a'];
        int end = lastPos[c - 'a'];
        if (start != -1 && end != -1 && end - start > 1) {
            unordered_set<char> middleChars;
            for (int i = start + 1; i < end; i++) {
                middleChars.insert(s[i]);
            }
            for (char mid : middleChars) {
                uniquePalindromes.insert(string(1, c) + mid + c);
            }
        }
    }

    return uniquePalindromes.size(); 
    }
};