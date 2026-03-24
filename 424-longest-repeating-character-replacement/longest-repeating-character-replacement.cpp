class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int freq[26] = {0};
        int ws = 0; //Windows Size Track
        int mf = 0; //for Maximum Frequency Track
        int ans = INT_MIN;

        int left = 0;

        for (int right = 0; right < n; right++) {

            freq[s[right] - 'A']++;
            mf = max(mf, freq[s[right] - 'A']); //finding max Freq

            ws = right - left + 1; // finding max window size

            while (ws - mf > k && left < right) {
                freq[s[left] - 'A']--;
                // yaha mf change nhi hoga (confusion)
                // becuase mf = window me kisi bhi character ki maximum frequency
                left++;
                ws = right - left + 1;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }

//     mf = "maximum frequency ever seen in window expansion"
//     👉 matlab:
//     mf sirf badhega
//     kabhi ghatega nahi
};