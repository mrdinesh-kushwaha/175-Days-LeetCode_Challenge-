class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int freq[26] = {0};
        int ws = 0;
        int mf = 0;
        int ans = INT_MIN;

        int left = 0;

        for (int right = 0; right < n; right++) {

            freq[s[right] - 'A']++;
            mf = max(mf, freq[s[right] - 'A']);

            ws = right - left + 1;

            while (ws - mf > k && left < right) {
                freq[s[left] - 'A']--;
                left++;
                ws = right - left + 1;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};